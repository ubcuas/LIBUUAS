#include "libuuas/waypoint.hpp"
#include "libuuas/utm.hpp"
#include <geos/geom.h>
#include <queue>
#include <unordered_set>

namespace libuuas {
namespace waypointing {

    static geos::geom::PrecisionModel precisionModel(geos::geom::PrecisionModel::Type::FLOATING);

    uuaspb::OrderedRouteResponse orderedRoute(uuaspb::OrderedRouteRequest ordered_route_request) {
        std::vector<Waypoint> auto_flight_wps;
        for (int i = 0; i < ordered_route_request.waypoints_size(); ++i) {
            switch (ordered_route_request.waypoints(i).waypoint_type()) {
            case uuaspb::WaypointType::AUTO_FLIGHT:
                auto_flight_wps.emplace_back(ordered_route_request.waypoints(i));
                std::cout << "afwp " << auto_flight_wps.rbegin()->latitude_dege7() << " " << auto_flight_wps.rbegin()->longitude_dege7() << std::endl;
                break;
            default:
                break;
            }
        }

        std::vector<CylinderObstacle> obstacles;
        for (int i = 0; i < ordered_route_request.obstacles_size(); ++i) {
            obstacles.emplace_back(ordered_route_request.obstacles(i));
        }

        Flyzone flyzone(ordered_route_request.flyzone());

        std::cout << "auto_flight_wps " << auto_flight_wps.size() << std::endl;
        Map flightMap(obstacles, flyzone);
        std::vector<Waypoint> generatedOrderedRoute = flightMap.generateOrderedRoute(auto_flight_wps);

        uuaspb::OrderedRouteResponse ordered_route_response;
        ordered_route_response.set_result(uuaspb::ResultStatus::OK);
        for (auto waypoint : generatedOrderedRoute) {
            auto pbWaypointPtr = ordered_route_response.add_waypoints();
            pbWaypointPtr->CopyFrom(waypoint.asProtobuf());
        }
        return ordered_route_response;
    }

    UasCoordinate::UasCoordinate() :
        _latitude_dege7(0), _longitude_dege7(0) {
    }

    UasCoordinate::UasCoordinate(uuaspb::UasCoordinate pbCoord) :
        _latitude_dege7(pbCoord.latitude_dege7()), _longitude_dege7(pbCoord.longitude_dege7()) {
    }

    UasCoordinate::UasCoordinate(int32_t latitude_dege7, int32_t longitude_dege7) :
        _latitude_dege7(latitude_dege7), _longitude_dege7(longitude_dege7) {
        utm::UTMData utmData = utm::from_latlon(latitude_dege7, longitude_dege7);
        this->_easting_m = utmData.easting_m;
        this->_northing_m = utmData.northing_m;
        this->_zone_number = utmData.zone_number;
        this->_zone_letter = utmData.zone_letter;
    }

    UasCoordinate::UasCoordinate(geos::geom::Coordinate geosCoord, int zoneNumber, char zoneLetter) :
        _easting_m(geosCoord.x), _northing_m(geosCoord.y), _zone_number(zoneNumber), _zone_letter(zoneLetter) {
        utm::LatLonData latlonData = utm::to_latlon(geosCoord.x, geosCoord.y, zoneNumber, zoneLetter);
        this->_latitude_dege7 = latlonData.latitude_dege7;
        this->_longitude_dege7 = latlonData.longitude_dege7;
    }

    UasCoordinate::UasCoordinate(geos::geom::Coordinate geosCoord) :
        _easting_m(geosCoord.x), _northing_m(geosCoord.y) {
        this->_zone_number = utm::cache::zone_number;
        this->_zone_letter = utm::cache::zone_letter;
        utm::LatLonData latlonData = utm::to_latlon(geosCoord.x, geosCoord.y);
        this->_latitude_dege7 = latlonData.latitude_dege7;
        this->_longitude_dege7 = latlonData.longitude_dege7;
    }

    uuaspb::UasCoordinate UasCoordinate::asProtobuf() const {
        uuaspb::UasCoordinate pbUasCoord;
        pbUasCoord.set_latitude_dege7(this->latitude_dege7());
        pbUasCoord.set_longitude_dege7(this->longitude_dege7());
        return pbUasCoord;
    }

    geos::geom::Coordinate UasCoordinate::asGeosCoordinate() const {
        return {this->_easting_m, this->_northing_m, 0};
    }

    std::unique_ptr<geos::geom::Point> UasCoordinate::asGeosPoint() const {
        geost::geomFactoryUPtr geoFactory = geos::geom::GeometryFactory::create(&precisionModel);
        geost::point* geoPoint = geoFactory->createPoint(this->asGeosCoordinate());
        geost::pointUPtr geoPointPtr = std::unique_ptr<geos::geom::Point>(geoPoint);
        return geoPointPtr;
    }

    int32_t UasCoordinate::latitude_dege7() const {
        return this->_latitude_dege7;
    }

    int32_t UasCoordinate::longitude_dege7() const {
        return this->_longitude_dege7;
    }

    double UasCoordinate::easting_m() const {
        return this->_easting_m;
    }

    double UasCoordinate::northing_m() const {
        return this->_northing_m;
    }

    bool operator!=(const UasCoordinate& a, const UasCoordinate& b) {
        return a.latitude_dege7() != b.latitude_dege7() || a.longitude_dege7() != b.longitude_dege7();
    }

    CylinderObstacle::CylinderObstacle(uuaspb::CylinderObstacle pbObstacle) :
        UasCoordinate(pbObstacle.coordinate()), _radius_m(pbObstacle.radius_m()), _height_m(pbObstacle.height_m()) {
    }

    CylinderObstacle::CylinderObstacle(int32_t latitude_dege7, int32_t longitude_dege7, double radius_m, double height_m) :
        UasCoordinate(latitude_dege7, longitude_dege7), _radius_m(radius_m), _height_m(height_m) {
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

    uuaspb::WaypointType asProtobuf(WaypointType waypointType) {
        switch (waypointType) {
        case WaypointType::COORDINATE:
            return uuaspb::WaypointType::COORDINATE;
            break;
        case WaypointType::GENERATED:
            return uuaspb::WaypointType::GENERATED;
            break;
        case WaypointType::AUTO_FLIGHT:
            return uuaspb::WaypointType::AUTO_FLIGHT;
            break;
        case WaypointType::AIRDROP:
            return uuaspb::WaypointType::AIRDROP;
            break;
        case WaypointType::OFF_AXIS:
            return uuaspb::WaypointType::OFF_AXIS;
            break;
        case WaypointType::SEARCH_GRID:
            return uuaspb::WaypointType::SEARCH_GRID;
            break;
        case WaypointType::NONE:
        default:
            return uuaspb::WaypointType::NONE;
            break;
        }
    }

    WaypointType fromProtobuf(uuaspb::WaypointType waypointType) {
        switch (waypointType) {
        case uuaspb::WaypointType::COORDINATE:
            return WaypointType::COORDINATE;
            break;
        case uuaspb::WaypointType::GENERATED:
            return WaypointType::GENERATED;
            break;
        case uuaspb::WaypointType::AUTO_FLIGHT:
            return WaypointType::AUTO_FLIGHT;
            break;
        case uuaspb::WaypointType::AIRDROP:
            return WaypointType::AIRDROP;
            break;
        case uuaspb::WaypointType::OFF_AXIS:
            return WaypointType::OFF_AXIS;
            break;
        case uuaspb::WaypointType::SEARCH_GRID:
            return WaypointType::SEARCH_GRID;
            break;
        case uuaspb::WaypointType::NONE:
        default:
            return WaypointType::NONE;
            break;
        }
    }

    Waypoint::Waypoint() :
        UasCoordinate(0.0, 0.0), _altitude_msl_m(0.0), _waypoint_type(WaypointType::NONE) { }

    Waypoint::Waypoint(uuaspb::Waypoint pbWaypoint) :
        UasCoordinate(pbWaypoint.coordinate()), _altitude_msl_m(pbWaypoint.altitude_msl_m()), _waypoint_type(::libuuas::waypointing::fromProtobuf(pbWaypoint.waypoint_type())) {
    }

    Waypoint::Waypoint(UasCoordinate coord, double altitude_msl_m, WaypointType waypoint_type) :
        UasCoordinate(coord.latitude_dege7(), coord.longitude_dege7()), _altitude_msl_m(altitude_msl_m), _waypoint_type(waypoint_type) { }

    Waypoint::Waypoint(int32_t latitude_dege7, int32_t longitude_dege7, double altitude_msl_m, WaypointType waypoint_type) :
        UasCoordinate(latitude_dege7, longitude_dege7), _altitude_msl_m(altitude_msl_m), _waypoint_type(waypoint_type) { }

    uuaspb::Waypoint Waypoint::asProtobuf() const {
        uuaspb::Waypoint pbWaypoint;
        pbWaypoint.mutable_coordinate()->CopyFrom(static_cast<const UasCoordinate*>(this)->asProtobuf());
        pbWaypoint.set_altitude_msl_m(this->altitude_msl_m());
        pbWaypoint.set_waypoint_type(::libuuas::waypointing::asProtobuf(this->waypoint_type()));
        return pbWaypoint;
    }

    UasCoordinate Waypoint::asUasCoordinate() const {
        return {this->latitude_dege7(), this->longitude_dege7()};
    }

    double Waypoint::altitude_msl_m() const {
        return this->_altitude_msl_m;
    }

    WaypointType Waypoint::waypoint_type() const {
        return this->_waypoint_type;
    }

    bool operator==(const Waypoint& a, const Waypoint& b) {
        return a.latitude_dege7() == b.latitude_dege7() && a.longitude_dege7() == b.longitude_dege7() && a.altitude_msl_m() == b.altitude_msl_m() && a.waypoint_type() == b.waypoint_type();
    }

    bool operator!=(const Waypoint& a, const Waypoint& b) {
        return a.latitude_dege7() != b.latitude_dege7() || a.longitude_dege7() != b.longitude_dege7() || a.altitude_msl_m() != b.altitude_msl_m() || a.waypoint_type() != b.waypoint_type();
    }

    Flyzone::Flyzone(uuaspb::Flyzone pbFlyzone) :
        _bounds({}),
        _max_altitude_msl_m(pbFlyzone.max_altitude_msl_m()),
        _min_altitude_msl_m(pbFlyzone.min_altitude_msl_m()) {
        for (int i = 0; i < pbFlyzone.bounds_size(); ++i) {
            this->_bounds.emplace_back(pbFlyzone.bounds(i));
        }
        if (*this->_bounds.begin() != *this->_bounds.rbegin()) {
            this->_bounds.push_back(*this->_bounds.begin());
        }
    }

    Flyzone::Flyzone(std::vector<UasCoordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m) :
        _bounds(bounds),
        _max_altitude_msl_m(max_altitude_msl_m),
        _min_altitude_msl_m(min_altitude_msl_m) {
            if (*this->_bounds.begin() != *this->_bounds.rbegin()) {
                this->_bounds.push_back(*this->_bounds.begin());
            }
        }

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

    Map::Map(std::vector<CylinderObstacle> obstacles, Flyzone flyzone) :
        _obstacles(obstacles), _flyzone(flyzone) {
        this->generatePointsOfInterests();
    }

    std::vector<Waypoint> Map::generateOrderedRoute(std::vector<Waypoint> ordered_wps) {
        this->generatePointsOfInterests();

        std::vector<Waypoint> outputRoute;
        outputRoute.push_back(ordered_wps[0]);

        for (auto it = ordered_wps.begin() + 1; it != ordered_wps.end(); ++it) {
            Waypoint start = *outputRoute.rbegin();
            Waypoint end = *it;

            std::vector<Waypoint> routeBetween = this->shortestRoute(start, end);
            for (auto rbit = routeBetween.begin() + 1; rbit != routeBetween.end(); ++rbit) {
                outputRoute.push_back(*rbit);
            }
        }

        return outputRoute;
    }

    double a_star_heuristic(UasCoordinate a, UasCoordinate b) {
        double dx = a.easting_m() - b.easting_m();
        double dy = a.northing_m() - b.northing_m();
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }

    std::vector<Waypoint> Map::shortestRoute(Waypoint start, Waypoint end) {
        std::cout << "smstart " << start.latitude_dege7() << " " << start.longitude_dege7() << std::endl;
        std::cout << "smend " << end.latitude_dege7() << " " << end.longitude_dege7() << std::endl;

        auto wpoi_connections = this->_wpoi_connections;
        auto flyable_wpoi = this->_flyable_wpoi;
        flyable_wpoi.push_back(start.asUasCoordinate());
        flyable_wpoi.push_back(end.asUasCoordinate());
        const size_t startIdx = flyable_wpoi.size() - 2;
        const size_t endIdx = flyable_wpoi.size() - 1;

        using PriorityWP = std::pair<int, size_t>; // <distance to goal, waypoint index>
        std::priority_queue<PriorityWP, std::vector<PriorityWP>, std::greater<PriorityWP>> frontier;
        frontier.push(std::make_pair(0, startIdx));
        std::unordered_map<size_t, int> cost_so_far;
        std::unordered_map<size_t, size_t> came_from;
        cost_so_far[startIdx] = 0;

        bool goal_reached = false;

        if (this->validRoute(flyable_wpoi[startIdx], flyable_wpoi[endIdx])) {
            std::cout << "Easy path found!" << std::endl;
            std::vector<Waypoint> output;
            output.push_back(start);
            output.push_back(end);
            return output;
        }
        for (size_t i = 0; i < flyable_wpoi.size() - 2; ++i) {
            if (this->validRoute(flyable_wpoi[startIdx], flyable_wpoi[i])) {
                wpoi_connections[i].push_back(startIdx);
                wpoi_connections[startIdx].push_back(i);
            }
            if (this->validRoute(flyable_wpoi[endIdx], flyable_wpoi[i])) {
                wpoi_connections[i].push_back(endIdx);
                wpoi_connections[endIdx].push_back(i);
            }
        }

        size_t current_wp_idx = startIdx;
        while (!frontier.empty()) {
            PriorityWP current_wp_pair = frontier.top();
            frontier.pop();

            current_wp_idx = std::get<1>(current_wp_pair);
            UasCoordinate current_wp = flyable_wpoi[current_wp_idx];
            std::cout << "curr " << current_wp.latitude_dege7() << " " << current_wp.longitude_dege7() << std::endl;

            if (current_wp.latitude_dege7() == end.latitude_dege7() && current_wp.longitude_dege7() == end.longitude_dege7()) {
                std::cout << "A* section done" << std::endl;
                goal_reached = true;
                break;
            }

            for (auto next_idx : wpoi_connections[current_wp_idx]) {
                std::cout << "next " << flyable_wpoi[next_idx].latitude_dege7() << " " << flyable_wpoi[next_idx].longitude_dege7() << std::endl;
                int new_cost = cost_so_far[current_wp_idx] + this->distance(flyable_wpoi[current_wp_idx], flyable_wpoi[next_idx]);
                if (cost_so_far.count(next_idx) == 0 || new_cost < cost_so_far[next_idx]) {
                    cost_so_far[next_idx] = new_cost;
                    int priority = new_cost + a_star_heuristic(flyable_wpoi[next_idx], end.asUasCoordinate());
                    frontier.push(std::make_pair(priority, next_idx));
                    came_from[next_idx] = current_wp_idx;
                }
            }
        }

        std::vector<Waypoint> output;
        if (goal_reached) {
            std::vector<int> output_idxs;
            size_t prev_idx = current_wp_idx;
            while (prev_idx != startIdx) {
                output_idxs.push_back(prev_idx);
                prev_idx = came_from[prev_idx];
            }

            output.push_back(start);
            const double alt_diff = end.altitude_msl_m() - start.altitude_msl_m();
            const double delta_alt = alt_diff / (output_idxs.size() - 1);
            double alt = start.altitude_msl_m();
            // Don't iterate through the start and the end since we already have those waypoints
            for (auto rit = output_idxs.rbegin() + 1; rit != output_idxs.rend() - 1; ++rit) {
                alt += delta_alt;
                output.emplace_back(flyable_wpoi[*rit], alt, WaypointType::GENERATED);
            }
            output.push_back(end);

        } else {
            std::cout << "No valid path found" << std::endl;
            output.push_back(start);
            output.push_back(end);
        }

        return output;
    }

    std::vector<Waypoint> Map::shortestRouteUnordered(Waypoint start, Waypoint end) {
        return this->shortestRoute(start, end);
    }

    bool Map::isCoordWithinFlyzone(UasCoordinate uasCoord) {
        return this->_flyzone.isCoordWithinFlyzone(uasCoord);
    }

    int Map::distance(UasCoordinate a, UasCoordinate b) {
        double dx = a.easting_m() - b.easting_m();
        double dy = a.northing_m() - b.northing_m();

        return sqrt(pow(dx, 2) + pow(dy, 2));
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
        std::vector<geost::coord> coords;
        coordArray.toVector(coords);
        for(auto coord : coords) {
            std::cout << "ls " << coord.x << " " << coord.y << std::endl;
        }

        bool isValid = true;
        geost::lineString* routeLineString = geoFactory->createLineString(&coordArray);
        if (!this->_flyzone.asGeosPoly()->contains(routeLineString) && isValid) {
            std::cout << "Not in FZ" << std::endl;
            std::vector<geost::coord> coords;
            this->_flyzone.asGeosPoly()->getCoordinates()->toVector(coords);
            for(auto coord : coords) {
                std::cout << coord.x << " " << coord.y << std::endl;
            }
            isValid = false;
        }
        for (auto obs : this->_obstacles) {
            if (routeLineString->intersects(obs.asGeosGeom().get()) && isValid) {
                std::cout << "Fat OBS" << std::endl;
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
                if (this->validRoute(this->_flyable_wpoi[i], this->_flyable_wpoi[j])) {
                    this->_wpoi_connections[i].push_back(j);
                    this->_wpoi_connections[j].push_back(i);
                }
            }
        }
    }

} // namespace waypointing
} // namespace libuuas
