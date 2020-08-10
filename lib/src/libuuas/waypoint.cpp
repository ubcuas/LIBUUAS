#include "libuuas/waypoint.hpp"
#include "libuuas/utm.hpp"
#include <geos/geos.h>
#include <unordered_set>
#include <queue>

namespace libuuas {
namespace waypointing {

    static geos::geom::PrecisionModel precisionModel(geos::geom::PrecisionModel::Type::FLOATING);

    std::vector<Waypoint> draw_full_route(std::vector<Waypoint> input_waypoints, std::vector<CylinderObstacle> input_obstacles, SearchGrid input_search_grid, Flyzone input_flyzone) {
        std::vector<Waypoint> auto_flight_wps;
        Waypoint airdrop_wp;
        Waypoint off_axis_wp;

        for (auto Waypoint : input_waypoints) {
            switch (Waypoint.waypoint_type()) {
            case WaypointType::AUTO_FLIGHT:
                auto_flight_wps.push_back(Waypoint);
                break;
            case WaypointType::AIRDROP:
                airdrop_wp = Waypoint;
                break;
            case WaypointType::OFF_AXIS:
                off_axis_wp = Waypoint;
                break;
            default:
                break;
            }
        }

        Map auto_flight_map = Map(auto_flight_wps, input_obstacles, input_flyzone);
        std::vector<Waypoint> auto_flight_route = auto_flight_map.generateOrderedRoute();
    }


    UasCoordinate::UasCoordinate() :
        _latitude(0), _longitude(0) {
    }

    UasCoordinate::UasCoordinate(double latitude, double longitude) :
        _latitude(latitude), _longitude(longitude) {
        utm::UTMData utmData = utm::from_latlon(latitude, longitude);
        this->_easting_m = utmData.easting_m;
        this->_northing_m = utmData.northing_m;
        this->_zone_number = utmData.zone_number;
        this->_zone_letter = utmData.zone_letter;
    }

    UasCoordinate::UasCoordinate(geos::geom::Coordinate geosCoord, int zoneNumber, char zoneLetter) :
        _easting_m(geosCoord.x), _northing_m(geosCoord.y), _zone_number(zoneNumber), _zone_letter(zoneLetter) {
        utm::LatLonData latlonData = utm::to_latlon(geosCoord.x, geosCoord.y, zoneNumber, zoneLetter);
        this->_latitude = latlonData.latitude;
        this->_longitude = latlonData.longitude;
    }

    UasCoordinate::UasCoordinate(geos::geom::Coordinate geosCoord) :
        _easting_m(geosCoord.x), _northing_m(geosCoord.y) {
        this->_zone_number = utm::cache::zone_number;
        this->_zone_letter = utm::cache::zone_letter;
        utm::LatLonData latlonData = utm::to_latlon(geosCoord.x, geosCoord.y);
        this->_latitude = latlonData.latitude;
        this->_longitude = latlonData.longitude;
    }

    geos::geom::Coordinate UasCoordinate::asGeosCoordinate() {
        return {this->_easting_m, this->_northing_m, 0};
    }

    std::unique_ptr<geos::geom::Point> UasCoordinate::asGeosPoint() {
        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);
        geost::point* geoPoint = geoFactory->createPoint(this->asGeosCoordinate());
        geost::pointUPtr geoPointPtr = std::unique_ptr<geos::geom::Point>(geoPoint);
        return geoPointPtr;
    }

    double UasCoordinate::latitude() {
        return this->_latitude;
    }

    double UasCoordinate::longitude() {
        return this->_longitude;
    }

    double UasCoordinate::easting_m() {
        return this->_easting_m;
    }

    double UasCoordinate::northing_m() {
        return this->_northing_m;
    }


    CylinderObstacle::CylinderObstacle(double latitude, double longitude, double radius_m, double height_m) :
        UasCoordinate(latitude, longitude), _radius_m(radius_m), _height_m(height_m) {
    }

    std::vector<UasCoordinate> CylinderObstacle::pointsOfInterest() {
        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);
        geost::coord obsCoord = this->asGeosCoordinate();
        geost::point* obsPoint = geoFactory->createPoint(obsCoord);

        constexpr int numSegments = 4;
        geost::geom* safeObsCircle = obsPoint->buffer(this->radius_m() + (safetyMargin_m * 2), numSegments);
        geost::coordSeq* safeObsCoords = safeObsCircle->getCoordinates();

        std::vector<UasCoordinate> safeObsUasCoords;
        for (size_t i = 0; i < safeObsCoords->size(); ++i) {
            safeObsUasCoords.emplace_back(safeObsCoords->getAt(i));
        }
        return safeObsUasCoords;
    }

    std::unique_ptr<geos::geom::Geometry> CylinderObstacle::asGeosGeom() {
        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);
        geost::coord obsCoord = this->asGeosCoordinate();
        geost::point* obsPoint = geoFactory->createPoint(obsCoord);
        geost::geom* obsCircle = obsPoint->buffer(this->radius_m());
        geost::geomUPtr obsCirclePtr = std::unique_ptr<geos::geom::Geometry>(obsCircle);
        return obsCirclePtr;
    }

    double CylinderObstacle::radius_m() {
        return this->_radius_m;
    }

    double CylinderObstacle::height_m() {
        return this->_height_m;
    }


    Waypoint::Waypoint() :
        UasCoordinate(0.0, 0.0), _altitude_msl_m(0.0), _waypoint_type(WaypointType::NONE) { }

    Waypoint::Waypoint(double latitude, double longitude, double altitude_msl_m, WaypointType waypoint_type) :
        UasCoordinate(latitude, longitude), _altitude_msl_m(altitude_msl_m), _waypoint_type(waypoint_type) { }

    double Waypoint::altitude_msl_m() {
        return this->_altitude_msl_m;
    }

    WaypointType Waypoint::waypoint_type() {
        return this->_waypoint_type;
    }


    Flyzone::Flyzone(std::vector<UasCoordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m) :
        _bounds(bounds),
        _max_altitude_msl_m(max_altitude_msl_m),
        _min_altitude_msl_m(min_altitude_msl_m) { }

    std::vector<UasCoordinate> Flyzone::pointsOfInterest() {
        geost::polyUPtr boundsPoly = this->asGeosPoly();
        geost::geom* safeBounds = boundsPoly->buffer(safetyMargin_m * -2);
        geost::coordSeq* safeBoundsCoords = safeBounds->getCoordinates();

        std::vector<UasCoordinate> safeBoundUasCoords;
        for (size_t i = 0; i < safeBoundsCoords->getSize(); ++i) {
            safeBoundUasCoords.emplace_back(safeBoundsCoords->getAt(i));
        }
        return safeBoundUasCoords;
    }

    std::unique_ptr<geos::geom::LinearRing> Flyzone::asGeosLinearRing() {
        geost::coordArray coordArray;

        for (auto coord : this->_bounds) {
            coordArray.add(coord.asGeosCoordinate());
        }

        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);
        geost::linearRing* boundsLinearRing = geoFactory->createLinearRing(coordArray);

        geost::linearRingUPtr boundsLinearRingPtr = std::unique_ptr<geos::geom::LinearRing>(boundsLinearRing);
        return boundsLinearRingPtr;
    }

    std::unique_ptr<geos::geom::Polygon> Flyzone::asGeosPoly() {
        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);
        geost::linearRingUPtr boundsLinearRing = this->asGeosLinearRing();
        geost::poly* flyzonePoly = geoFactory->createPolygon(*boundsLinearRing, {});

        geost::polyUPtr flyzonePolyPtr = std::unique_ptr<geos::geom::Polygon>(flyzonePoly);
        return flyzonePolyPtr;
    }

    bool Flyzone::isCoordWithinFlyzone(UasCoordinate uasCoord) {
        return this->isCoordWithinFlyzone(uasCoord.asGeosPoint());
    }

    bool Flyzone::isCoordWithinFlyzone(std::unique_ptr<geos::geom::Point> point) {
        geost::polyUPtr flyzoneGeom = this->asGeosPoly();
        geost::geom* pointGeom = static_cast<geos::geom::Geometry*>(point.get());
        return flyzoneGeom->contains(pointGeom);
    }


    Map::Map(std::vector<Waypoint> ordered_wps, std::vector<CylinderObstacle> obstacles, Flyzone flyzone) :
        _ordered_wps(ordered_wps), _obstacles(obstacles), _flyzone(flyzone) { }

    std::vector<Waypoint> Map::generateOrderedRoute() {
        this->generatePointsOfInterests();
    }

    double a_star_heuristic(UasCoordinate a, UasCoordinate b) {
        double dx = a.easting_m() - b.easting_m();
        double dy = a.northing_m() - b.northing_m();
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    // std::vector<Waypoint> Map::shortestRoute(Waypoint start, Waypoint end) {
    //     using PriorityWP = std::pair<int, Waypoint>;
    //     std::priority_queue<PriorityWP, std::vector<PriorityWP>, std::greater<PriorityWP>> frontier;
    //     frontier.push(std::make_pair(0, start));

    //     bool goal_reached = false;

    //     auto flyable_wpoi = this->_flyable_wpoi;
    //     flyable_wpoi.push_back(end.asUasCoordinate());
    //     for (auto coord : this->_flyable_wpoi) {

    //     }

    //     while(!frontier.empty()) {
    //         Waypoint current_wp = frontier.pop();

    //         if(current_wp.latitude() == end.latitude() && current_wp.longitude() == end.longitude()) {
    //             std::cout << "A* section done" << std::endl;
    //             goal_reached = true;
    //             break;
    //         }



    //     }
    // }

// def a_star_search(graph, start, goal):
//     # logger.debug("A* Pathfinding start for %s to %s", start, goal)
//     frontier = PriorityQueue()
//     frontier.put(start, 0)
//     came_from = {}
//     cost_so_far = {}
//     came_from[start] = None
//     cost_so_far[start] = 0
//     goal_reached = None

//     while not frontier.is_empty():
//         current = frontier.get()

//         if all(current[dimension] == goal[dimension] for dimension in ['latitude', 'longitude']):
//             # logger.debug("A* Pathfinding complete for %s to %s", start, goal)
//             goal_reached = True
//             break

//         for next in graph.neighbors(current):
//             new_cost = cost_so_far[current] + graph.cost(current, next)
//             if next not in cost_so_far or new_cost < cost_so_far[next]:
//                 cost_so_far[next] = new_cost
//                 priority = new_cost + heuristic(goal, next)
//                 frontier.put(next, priority)
//                 came_from[next] = current

//     if goal_reached:
//         output = []
//         prev = current
//         while prev is not None:
//             output.append(prev)
//             prev = came_from[prev]
//         output.reverse()
//     else:
//         logger.error("No valid path found for %s to %s", start, goal)
//         output = [start, goal]

//     return output


    bool Map::isCoordWithinFlyzone(UasCoordinate uasCoord) {
        return this->_flyzone.isCoordWithinFlyzone(uasCoord);
    }

    bool Map::validRoute(Waypoint start, Waypoint end) {
        return this->validRoute(static_cast<UasCoordinate*>(&start), static_cast<UasCoordinate*>(&end));
    }

    bool Map::validRoute(Waypoint start, UasCoordinate end) {
        return this->validRoute(static_cast<UasCoordinate*>(&start), &end);
    }

    bool Map::validRoute(UasCoordinate start, UasCoordinate end) {
        return this->validRoute(&start, &end);
    }

    bool Map::validRoute(UasCoordinate* start, UasCoordinate* end) {
        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);

        geost::coordArray coordArray;
        coordArray.add(start->asGeosCoordinate());
        coordArray.add(end->asGeosCoordinate());

        bool isValid = true;
        geost::lineString* routeLineString = geoFactory->createLineString(&coordArray);
        if (!this->_flyzone.asGeosPoly()->contains(routeLineString) && isValid) {
            isValid = false;
        }
        for (auto obs : this->_obstacles) {
            if (routeLineString->intersects(obs.asGeosGeom().get()) && isValid) {
                isValid = false;
                break;
            }
        }
        return isValid;
    }

    void Map::generatePointsOfInterests() {
        // Generate the points of interest
        std::vector<UasCoordinate> _potential_wpoi;
        for (auto coord : this->_flyzone.pointsOfInterest()) {
            _potential_wpoi.push_back(coord);
        }

        for (auto obstacle : this->_obstacles) {
            for (auto coord : obstacle.pointsOfInterest()) {
                _potential_wpoi.push_back(coord);
            }
        }

        // Filter out invalid POIs
        for (auto coord : _potential_wpoi) {
            if (this->isCoordWithinFlyzone(coord)) {
                this->_flyable_wpoi.push_back(coord);
            }
        }

        // Generate available connections between maps
        for (size_t i = 0; i < this->_flyable_wpoi.size(); ++i) {
            for (size_t j = i + 1; j < this->_flyable_wpoi.size(); ++j) {
                if (this->validRoute(_flyable_wpoi[i], _flyable_wpoi[j])) {
                    _wpoi_connections[i].push_back(j);
                    _wpoi_connections[j].push_back(i);
                }
            }
        }
    }

} // namespace waypointing
} // namespace libuuas
