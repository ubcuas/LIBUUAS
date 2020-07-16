#include "libuuas/waypoint.hpp"
#include <geos/geom/CoordinateArraySequence.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/LinearRing.h>

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
    auto auto_flight_route = auto_flight_map.generateOrderedRoute();
}

Flyzone::Flyzone(std::vector<UasCoordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m) :
    _bounds(bounds),
    _max_altitude_msl_m(max_altitude_msl_m),
    _min_altitude_msl_m(min_altitude_msl_m) { }

std::vector<UasCoordinate> Flyzone::pointsOfInterest() {
    geos::geom::CoordinateArraySequence coordArray;

    for (auto coord : this->_bounds) {
        coordArray.add(coord.asGeosCoordinate());
    }

    auto geoFactory = geos::geom::GeometryFactory::create();
    auto boundsLinearRing = geoFactory->createLinearRing();
    boundsLinearRing->setPoints(&coordArray);

    auto safeBounds = boundsLinearRing->buffer(safetyMargin_m * -2);
    auto safeBoundsCoords = safeBounds->getCoordinates();

    std::vector<UasCoordinate> safeBoundUasCoords;
    for (size_t i = 0; i < safeBoundsCoords->size(); ++i) {
        safeBoundUasCoords.emplace_back(safeBoundsCoords->getAt(i));
    }

    return safeBoundUasCoords;
}

Map::Map(std::vector<Waypoint> ordered_wps, std::vector<CylinderObstacle> obstacles, Flyzone flyzone) :
    _ordered_wps(ordered_wps), _obstacles(obstacles), _flyzone(flyzone) { }

std::vector<Waypoint> Map::generateOrderedRoute() {
    this->generatePointsOfInterestMap();
}

void Map::generatePointsOfInterestMap() {
    for (auto coord : this->_flyzone.pointsOfInterest()) {
        this->_flyable_wpoi.push_back(coord);
    }

    for (auto obstacle : this->_obstacles) {
        for (auto coord : obstacle.pointsOfInterest()) {
            this->_flyable_wpoi.push_back(coord);
        }
    }
}
