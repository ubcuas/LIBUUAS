#include <catch2/catch.hpp>
#include <libuuas/waypoint.hpp>

TEST_CASE("UASCoordinates convert to GEOSCoordinates losslessly", "[waypoint]") {
    const double latitude_value = 43.1561681;
    const double longitude_value = -75.8449946;

    UasCoordinate original_uascoord(latitude_value, longitude_value);
    geos::geom::Coordinate geoscoord = original_uascoord.asGeosCoordinate();
    UasCoordinate converted_uascoord(geoscoord);

    REQUIRE(original_uascoord.latitude() == latitude_value);
    REQUIRE(original_uascoord.longitude() == longitude_value);
    REQUIRE(original_uascoord.latitude() == converted_uascoord.latitude());
    REQUIRE(original_uascoord.longitude() == converted_uascoord.longitude());
}
