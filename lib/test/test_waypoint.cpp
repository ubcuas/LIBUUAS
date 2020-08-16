#define private public

#include "test_utils.hpp"
#include <catch2/catch.hpp>
#include <libuuas/waypoint.hpp>

using namespace libuuas::waypointing;

std::vector<UasCoordinate> testFlyzoneBounds = {{38.153364, -76.436760}, {38.148429, -76.417743}, {38.140846, -76.423239}, {38.141798, -76.435273}, {38.153364, -76.436760}};
Flyzone testFlyzone(testFlyzoneBounds, 50, 5);

TEST_CASE("UASCoordinates convert to geost::coordinates with required precision", "[waypoint]") {
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

TEST_CASE("Obstacles points of interest generate at a low resolution", "[waypoint]") {
    constexpr double latitude = 43.1561681;
    constexpr double longitude = -75.8449946;
    constexpr double radius_m = 16;
    constexpr double height_m = 20;

    CylinderObstacle cylinderObstacle(latitude, longitude, radius_m, height_m);
    std::vector<UasCoordinate> pois = cylinderObstacle.pointsOfInterest();

    constexpr int numSegments = 4;
    REQUIRE(pois.size() == numSegments * 4 + 1);
}

TEST_CASE("Map connections should generate bi-directional routes", "[waypoint]") {
    Map testMap({}, {}, testFlyzone);
    testMap.generatePointsOfInterests();

    REQUIRE(testMap._wpoi_connections.size() == 5);
    REQUIRE(testMap._wpoi_connections[0][0] == 1);
    REQUIRE(testMap._wpoi_connections[0].size() == 3);
    REQUIRE(testMap._wpoi_connections[1][0] == 0);
    REQUIRE(testMap._wpoi_connections[1].size() == 4);
}

TEST_CASE("Map shortest route should be straight line when no obstacles", "[waypoint][shortest]") {
    Map testMap({}, {}, testFlyzone);
    testMap.generatePointsOfInterests();

    Waypoint start(38.144988, -76.429635, 35, WaypointType::AUTO_FLIGHT);
    Waypoint end(38.145332, -76.428650, 35, WaypointType::AUTO_FLIGHT);

    std::vector<Waypoint> result = testMap.shortestRoute(start, end);
    REQUIRE(result.size() == 2);
    REQUIRE(result[0] == start);
    REQUIRE(result[1] == end);
}

TEST_CASE("Map shortest route should avoid single obstacle", "[waypoint][shortest]") {
    constexpr double cylRadius = 25;
    CylinderObstacle obs(38.144692, -76.427995, cylRadius, 70);

    Map testMap({}, {obs}, testFlyzone);
    testMap.generatePointsOfInterests();

    Waypoint start(38.143665, -76.426940, 35, WaypointType::AUTO_FLIGHT);
    Waypoint end(38.146276, -76.429538, 35, WaypointType::AUTO_FLIGHT);

    std::vector<Waypoint> result = testMap.shortestRoute(start, end);
    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == start);
    REQUIRE(result[2] == end);

    UasCoordinate obsCoord = static_cast<UasCoordinate>(obs);
    REQUIRE(testMap.distance(obsCoord, result[1]) > cylRadius);
}
