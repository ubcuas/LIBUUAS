#define private public
#include "test_utils.hpp"
#include <catch2/catch.hpp>
#include <libuuas/utm.hpp>
#include <iostream>

using namespace libuuas::utm;

TEST_CASE("Should convert a latlon to the correct utm", "[utm]") {
    const int32_t latitude = -271860912;  // -27.1860912
    const int32_t longitude = -1094350841;  // -109.4350841

    const double correct_easting = 655018.34;
    const double correct_northing = 6991985.79;
    const int correct_zone_number = 12;
    const char correct_zone_letter = 'J';

    UTMData utmData = from_latlon(latitude, longitude);

    REQUIRE(comparePrecision(correct_easting, utmData.easting_m, 2));
    REQUIRE(comparePrecision(correct_northing, utmData.northing_m, 2));
    REQUIRE(correct_zone_number == utmData.zone_number);
    REQUIRE(correct_zone_letter == utmData.zone_letter);
}

TEST_CASE("Should convert a utm to the correct latlon", "[utm]") {
    const int32_t correct_latitude = 419022289;  // 41.9022289
    const int32_t correct_longitude = 124569847;  // 12.4569847

    const double easting = 289063.87;
    const double northing = 4642048.33;
    const int zone_number = 33;
    const char zone_letter = 'T';

    LatLonData latlonData = to_latlon(easting, northing, zone_number, zone_letter);

    std::cout << correct_latitude << " " << correct_longitude << std::endl;
    std::cout << latlonData.latitude_dege7 << " " << latlonData.longitude_dege7 << std::endl;

    REQUIRE(correct_latitude == latlonData.latitude_dege7);
    REQUIRE(correct_longitude == latlonData.longitude_dege7);
}

TEST_CASE("Should convert a utm to the correct latlon using cached zone information", "[utm]") {
    const long double latitude = -27.1860909;
    const long double longitude = -109.4350839;

    const double correct_easting = 655018.36;
    const double correct_northing = 6991985.83;
    const int correct_zone_number = 12;
    const char correct_zone_letter = 'J';

    UTMData utmData = from_latlon(latitude, longitude);

    std::cout << correct_easting << " " << correct_northing << std::endl;
    std::cout << utmData.easting_m << " " << utmData.northing_m << std::endl;

    REQUIRE(comparePrecision(correct_easting, utmData.easting_m, 2));
    REQUIRE(comparePrecision(correct_northing, utmData.northing_m, 2));
    REQUIRE(correct_zone_number == utmData.zone_number);
    REQUIRE(correct_zone_letter == utmData.zone_letter);

    LatLonData latlonData = to_latlon(utmData.easting_m, utmData.northing_m);

    REQUIRE(latitude == latlonData.latitude_dege7);
    REQUIRE(longitude == latlonData.longitude_dege7);
}
