#pragma once

#include <stdint.h>

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
        int32_t latitude_dege7;
        int32_t longitude_dege7;
    };

    struct UTMData {
        double easting_m;
        double northing_m;
        int zone_number;
        char zone_letter;
    };

    LatLonData to_latlon(double easting, double northing, int zone_number, char zone_letter);
    LatLonData to_latlon(double easting, double northing);
    UTMData from_latlon(int32_t latitude_dege7, int32_t longitude_dege7);

} // utm
} // libuuas
