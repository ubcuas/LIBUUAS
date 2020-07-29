#define private public
#include "test_utils.hpp"
#include <catch2/catch.hpp>
#include <libuuas/utm.hpp>

using namespace libuuas::utm;

TEST_CASE("Should convert a latlon to the correct utm", "[utm]") {
    const long double latitude = -27.186091;
    const long double longitude = -109.435084;

    const long double correct_easting = 655018.35;
    const long double correct_northing = 6991985.82;
    const int correct_zone_number = 12;
    const char correct_zone_letter = 'J';

    UTMData utmData = from_latlon(latitude, longitude);

    REQUIRE(comparePrecision(correct_easting, utmData.easting_m, 2));
    REQUIRE(comparePrecision(correct_northing, utmData.northing_m, 2));
    REQUIRE(correct_zone_number == utmData.zone_number);
    REQUIRE(correct_zone_letter == utmData.zone_letter);
}

TEST_CASE("Should convert a utm to the correct latlon", "[utm]") {
    const long double correct_latitude = 41.9022289;
    const long double correct_longitude = 12.4569847;

    const long double easting = 289063.95;
    const long double northing = 4642048.32;
    const int zone_number = 33;
    const char zone_letter = 'T';

    LatLonData latlonData = to_latlon(easting, northing, zone_number, zone_letter);

    REQUIRE(comparePrecisionTrunc(correct_latitude, latlonData.latitude, 6));
    REQUIRE(comparePrecisionTrunc(correct_longitude, latlonData.longitude, 6));
}

TEST_CASE("Should convert a utm to the correct latlon using cached zone information", "[utm]") {
    const long double latitude = -27.1860909;
    const long double longitude = -109.4350839;

    const long double correct_easting = 655018.36;
    const long double correct_northing = 6991985.83;
    const int correct_zone_number = 12;
    const char correct_zone_letter = 'J';

    UTMData utmData = from_latlon(latitude, longitude);

    REQUIRE(comparePrecision(correct_easting, utmData.easting_m, 2));
    REQUIRE(comparePrecision(correct_northing, utmData.northing_m, 2));
    REQUIRE(correct_zone_number == utmData.zone_number);
    REQUIRE(correct_zone_letter == utmData.zone_letter);

    LatLonData latlonData = to_latlon(utmData.easting_m, utmData.northing_m);

    REQUIRE(comparePrecisionTrunc(latitude, latlonData.latitude, 6));
    REQUIRE(comparePrecisionTrunc(longitude, latlonData.longitude, 6));
}
