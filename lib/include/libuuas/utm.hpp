#pragma once

namespace libuuas {
namespace utm {
    namespace cache {
        static int zone_number = 0;
        static char zone_letter = 'A';
    } // cache
} // utm
} // libuuas

namespace libuuas {
namespace utm {
    struct LatLonData {
        long double latitude;
        long double longitude;
    };

    struct UTMData {
        long double easting_m;
        long double northing_m;
        int zone_number;
        char zone_letter;
    };

    LatLonData to_latlon(long double easting, long double northing, int zone_number, char zone_letter);
    LatLonData to_latlon(long double easting, long double northing);
    UTMData from_latlon(long double latitude, long double longitude);

} // utm
} // libuuas
