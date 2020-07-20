#define private public
#include <catch2/catch.hpp>
#include <libuuas/waypoint.hpp>

using namespace libuuas::waypointing;

std::vector<UasCoordinate> testFlyzoneBounds = {{38.153364, -76.436760}, {38.148429, -76.417743}, {38.140846, -76.423239}, {38.141798, -76.435273}, {38.153364, -76.436760}};
Flyzone testFlyzone(testFlyzoneBounds, 50, 5);

TEST_CASE("UASCoordinates convert to geost::coordinates losslessly", "[waypoint]") {
    const double latitude_value = 43.1561681;
    const double longitude_value = -75.8449946;

    UasCoordinate original_uascoord(latitude_value, longitude_value);
    geos::geom::Coordinate geosCoord = original_uascoord.asGeosCoordinate();
    UasCoordinate converted_uascoord(geosCoord);

    REQUIRE(original_uascoord.latitude() == latitude_value);
    REQUIRE(original_uascoord.longitude() == longitude_value);
    REQUIRE(original_uascoord.latitude() == converted_uascoord.latitude());
    REQUIRE(original_uascoord.longitude() == converted_uascoord.longitude());
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

TEST_CASE("Map should generate bi-directional routes", "[waypoint]") {
    constexpr double start_latitude = 43.1561681;
    constexpr double start_longitude = -75.8449946;

    constexpr double end_latitude = 43.1561681;
    constexpr double end_longitude = -75.8449946;

    constexpr double alt = 30;

    std::vector<Waypoint> ordered_wps = {
        {start_latitude, start_longitude, alt, WaypointType::AUTO_FLIGHT},
        {end_latitude, end_longitude, alt, WaypointType::AUTO_FLIGHT},
    };

    Map testMap(ordered_wps, {}, testFlyzone);
    testMap.generatePointsOfInterests();

    REQUIRE(testMap._wpoi_connections.size() == 2);
    REQUIRE(testMap._wpoi_connections[0][0] == 1);
    REQUIRE(testMap._wpoi_connections[0].size() == 1);
    REQUIRE(testMap._wpoi_connections[0][1] == 0);
    REQUIRE(testMap._wpoi_connections[0].size() == 1);
}
