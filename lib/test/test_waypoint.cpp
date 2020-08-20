#define private public

#include "test_utils.hpp"
#include <catch2/catch.hpp>
#include <libuuas/waypoint.hpp>
#include <tuple>
#include <vector>

using namespace libuuas::waypointing;

std::vector<UasCoordinate> testFlyzoneBounds = {{38.153364, -76.436760}, {38.148429, -76.417743}, {38.140846, -76.423239}, {38.141798, -76.435273}};
Flyzone testFlyzone() {
    return {testFlyzoneBounds, 50, 5};
}

TEST_CASE("Flyzone should generate complete set of points of interest", "[waypoint][flyzone]") {
    std::vector<UasCoordinate> results = testFlyzone().pointsOfInterest();
    REQUIRE(results.size() == 5);
}

TEST_CASE("UASCoordinates convert to geost::coordinates with required precision", "[waypoint][uascoordinate]") {
    const double latitude_value = 43.1561681;
    const double longitude_value = -75.8449946;

    UasCoordinate original_uascoord(latitude_value, longitude_value);
    geos::geom::Coordinate geosCoord = original_uascoord.asGeosCoordinate();
    UasCoordinate converted_uascoord(geosCoord);

    REQUIRE(original_uascoord.latitude() == latitude_value);
    REQUIRE(original_uascoord.longitude() == longitude_value);
    REQUIRE(comparePrecisionTrunc(original_uascoord.latitude(), converted_uascoord.latitude(), 7));
    REQUIRE(comparePrecisionTrunc(original_uascoord.longitude(), converted_uascoord.longitude(), 7));
}

TEST_CASE("Obstacles points of interest generate at a low resolution", "[waypoint][uascoordinate]") {
    constexpr double latitude = 43.1561681;
    constexpr double longitude = -75.8449946;
    constexpr double radius_m = 16;
    constexpr double height_m = 20;

    CylinderObstacle cylinderObstacle(latitude, longitude, radius_m, height_m);
    std::vector<UasCoordinate> pois = cylinderObstacle.pointsOfInterest();

    constexpr int numSegments = 4;
    REQUIRE(pois.size() == numSegments * 4 + 1);
}

TEST_CASE("Map connections should generate bi-directional routes", "[waypoint][uascoordinate]") {
    Map testMap({}, testFlyzone());

    REQUIRE(testMap._wpoi_connections.size() == 5);
    REQUIRE(testMap._wpoi_connections[0][0] == 1);
    REQUIRE(testMap._wpoi_connections[0].size() == 3);
    REQUIRE(testMap._wpoi_connections[1][0] == 0);
    REQUIRE(testMap._wpoi_connections[1].size() == 4);
}

TEST_CASE("Map shortestRoute should be straight line when no obstacles", "[waypoint][shortest]") {
    Map testMap({}, testFlyzone());

    Waypoint start(38.144988, -76.429635, 35, WaypointType::AUTO_FLIGHT);
    Waypoint end(38.145332, -76.428650, 35, WaypointType::AUTO_FLIGHT);

    std::vector<Waypoint> result = testMap.shortestRoute(start, end);
    REQUIRE(result.size() == 2);
    REQUIRE(result[0] == start);
    REQUIRE(result[1] == end);
}

TEST_CASE("Map shortestRoute should avoid single obstacle", "[waypoint][shortest]") {
    constexpr double cylRadius = 25;
    CylinderObstacle obs(38.144692, -76.427995, cylRadius, 70);

    Map testMap({obs}, testFlyzone());

    Waypoint start(38.143665, -76.426940, 35, WaypointType::AUTO_FLIGHT);
    Waypoint end(38.146276, -76.429538, 35, WaypointType::AUTO_FLIGHT);

    std::vector<Waypoint> result = testMap.shortestRoute(start, end);
    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == start);
    REQUIRE(result[2] == end);

    UasCoordinate obsCoord = static_cast<UasCoordinate>(obs);
    REQUIRE(testMap.distance(obsCoord, result[1]) > cylRadius);
}

TEST_CASE("Map orderedRoute should avoid single obstacle", "[waypoint][ordered]") {
    std::vector<std::tuple<double, double, double, uuaspb::WaypointType>> waypoints = {{38.143665, -76.426940, 35, uuaspb::WaypointType::AUTO_FLIGHT}, {38.146276, -76.429538, 35, uuaspb::WaypointType::AUTO_FLIGHT}};

    uuaspb::OrderedRouteRequest request;
    for(auto wp: waypoints) {
        auto* pbwp = request.add_waypoints();
        pbwp->mutable_coordinate()->set_latitude(std::get<0>(wp));
        pbwp->mutable_coordinate()->set_longitude(std::get<1>(wp));
        pbwp->set_altitude_msl_m(std::get<2>(wp));
        pbwp->set_waypoint_type(std::get<3>(wp));
    }
    auto* pbobs = request.add_obstacles();
    pbobs->mutable_coordinate()->set_latitude(38.144692);
    pbobs->mutable_coordinate()->set_longitude(-76.427995);
    pbobs->set_radius_m(25);
    pbobs->set_height_m(70);

    request.mutable_flyzone()->set_max_altitude_msl_m(50);
    request.mutable_flyzone()->set_min_altitude_msl_m(5);
    for(auto bound: testFlyzoneBounds) {
        auto* pbbound = request.mutable_flyzone()->add_bounds();
        pbbound->set_latitude(bound.latitude());
        pbbound->set_latitude(bound.longitude());
    }

    uuaspb::OrderedRouteResponse response = orderedRoute(request);
    // std::vector<Waypoint> result = testMap.shortestRoute(start, end);
    // REQUIRE(result.size() == 3);
    // REQUIRE(result[0] == start);
    // REQUIRE(result[2] == end);

    // UasCoordinate obsCoord = static_cast<UasCoordinate>(obs);
    // REQUIRE(testMap.distance(obsCoord, result[1]) > cylRadius);
}
