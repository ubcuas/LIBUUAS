#include "libuuas/waypoint.hpp"
#include <geos/geom/CoordinateArraySequence.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/LinearRing.h>
#include <geos/geom/Point.h>

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

UasCoordinate::UasCoordinate(double latitude, double longitude) :
    _latitude(latitude), _longitude(longitude) { }

UasCoordinate::UasCoordinate(geos::geom::Coordinate geosCoord) :
    // TODO: should convert from UTM
    _latitude(geosCoord.x),
    _longitude(geosCoord.y) { }

geos::geom::Coordinate UasCoordinate::asGeosCoordinate() {
    // TODO: Should be easting/northing
    return {this->latitude(), this->longitude(), 0};
}

double UasCoordinate::latitude() {
    return this->_latitude;
}

double UasCoordinate::longitude() {
    return this->_longitude;
}

CylinderObstacle::CylinderObstacle(double latitude, double longitude, double radius_m, double height_m) :
    UasCoordinate(latitude, longitude), _radius_m(radius_m), _height_m(height_m) {
}

std::vector<UasCoordinate> CylinderObstacle::pointsOfInterest() {
    auto geoFactory = geos::geom::GeometryFactory::create();
    auto obsCoord = this->asGeosCoordinate();
    auto obsPoint = geoFactory->createPoint(obsCoord);

    constexpr int numSegments = 16;
    auto safeObsCircle = obsPoint->buffer(this->radius_m() + (safetyMargin_m * 2), numSegments);
    auto safeObsCoords = safeObsCircle->getCoordinates();

    std::vector<UasCoordinate> safeObsUasCoords;
    for (size_t i = 0; i < safeObsCoords->size(); ++i) {
        safeObsUasCoords.emplace_back(safeObsCoords->getAt(i));
    }
    return safeObsUasCoords;
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

WaypointType Waypoint::waypoint_type() {
    return this->_waypoint_type;
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
