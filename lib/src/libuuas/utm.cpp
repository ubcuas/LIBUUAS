#include "libuuas/utm.hpp"
#include <cmath>
#include <iostream>
#include <tuple>

namespace libuuas {
namespace utm {

    const long double K0 = 0.9996;

    const long double E = 0.00669438;
    const long double E2 = E * E;
    const long double E3 = E2 * E;
    const long double E_P2 = E / (1.0 - E);

    const long double SQRT_E = sqrt(1 - E);
    const long double _E = (1 - SQRT_E) / (1 + SQRT_E);
    const long double _E2 = _E * _E;
    const long double _E3 = _E2 * _E;
    const long double _E4 = _E3 * _E;
    const long double _E5 = _E4 * _E;

    const long double M1 = (1 - E / 4 - 3 * E2 / 64 - 5 * E3 / 256);
    const long double M2 = (3 * E / 8 + 3 * E2 / 32 + 45 * E3 / 1024);
    const long double M3 = (15 * E2 / 256 + 45 * E3 / 1024);
    const long double M4 = (35 * E3 / 3072);

    const long double P2 = (3. / 2 * _E - 27. / 32 * _E3 + 269. / 512 * _E5);
    const long double P3 = (21. / 16 * _E2 - 55. / 32 * _E4);
    const long double P4 = (151. / 96 * _E3 - 417. / 128 * _E5);
    const long double P5 = (1097. / 512 * _E4);

    const long double R = 6378137;

    constexpr char ZONE_LETTERS[] = "CDEFGHJKLMNPQRSTUVWXX";

    long double degToRad(long double degrees) {
        return (degrees * M_PI) / 180;
    }

    long double radToDeg(long double radians) {
        return (radians * 180) / M_PI;
    }

    bool in_range(long double input, long double min, long double max) {
        if (input > min && input < max) {
            return true;
        } else {
            return false;
        }
    }

    char latitude_to_zone_letter(long double latitude) {
        if (-80.0 <= latitude <= 84.0) {
            return ZONE_LETTERS[static_cast<int>(latitude + 80) >> 3];
        } else {
            // raise ERROR
            return 'A';
        }
    }

    int latlon_to_zone_number(long double latitude, long double longitude) {
        if (56.0 <= latitude && latitude < 64.0 && 3.0 <= longitude && longitude < 12.0) {
            return 32;
        }

        if (72.0 <= latitude <= 84.0 && longitude >= 0) {
            if (longitude < 9) {
                return 31;
            } else if (longitude < 21) {
                return 33;
            } else if (longitude < 33) {
                return 35;
            } else if (longitude < 42) {
                return 37;
            }
        }

        return static_cast<int>((longitude + 180) / 6) + 1;
    }

    long double zone_number_to_central_longitude(int zone_number) {
        long double zone_number_int = static_cast<long double>(zone_number);
        return (zone_number_int - 1.0) * 6.0 - 180.0 + 3.0;
    }

    LatLonData to_latlon(long double easting, long double northing, int zone_number, char zone_letter) {
        if (!in_range(easting, 100000, 1000000)) {
            // throw error
        }
        if (!in_range(northing, 0, 10000000)) {
            // throw error
        }

        const bool northern = (zone_letter >= 'N');

        long double x = easting - 500000;
        long double y = northing;

        if (!northern) {
            y -= 10000000;
        }

        const long double m = y / K0;
        const long double mu = m / (R * M1);

        const long double p_rad = (mu + P2 * sin(2 * mu) + P3 * sin(4 * mu) + P4 * sin(6 * mu) + P5 * sin(8 * mu));

        const long double p_sin = sin(p_rad);
        const long double p_sin2 = p_sin * p_sin;

        const long double p_cos = cos(p_rad);

        const long double p_tan = p_sin / p_cos;
        const long double p_tan2 = p_tan * p_tan;
        const long double p_tan4 = p_tan2 * p_tan2;

        const long double ep_sin = 1 - E * p_sin2;
        const long double ep_sin_sqrt = sqrt(1 - E * p_sin2);

        const long double n = R / ep_sin_sqrt;
        const long double r = (1 - E) / ep_sin;

        const long double c = _E * pow(p_cos, 2);
        const long double c2 = c * c;

        const long double d = x / (n * K0);
        const long double d2 = d * d;
        const long double d3 = d2 * d;
        const long double d4 = d3 * d;
        const long double d5 = d4 * d;
        const long double d6 = d5 * d;

        const long double latitude_rad = (p_rad - (p_tan / r) * (d2 / 2 - d4 / 24 * (5 + 3 * p_tan2 + 10 * c - 4 * c2 - 9 * E_P2)) + d6 / 720 * (61 + 90 * p_tan2 + 298 * c + 45 * p_tan4 - 252 * E_P2 - 3 * c2));

        const long double longitude_rad = (d - d3 / 6 * (1 + 2 * p_tan2 + c) + d5 / 120 * (5 - 2 * c + 28 * p_tan2 - 3 * c2 + 8 * E_P2 + 24 * p_tan4)) / p_cos;

        return {radToDeg(latitude_rad),
            radToDeg(longitude_rad) + zone_number_to_central_longitude(zone_number)};
    }

    LatLonData to_latlon(long double easting, long double northing) {
        return to_latlon(easting, northing, cache::zone_number, cache::zone_letter);
    }

    UTMData from_latlon(long double latitude, long double longitude) {
        if (!in_range(latitude, -80.0, 84.0)) {
            // TODO: RAISE ERROR
        }
        if (!in_range(longitude, -180.0, 84.0)) {
            // TODO: RAISE ERROR
        }

        const long double lat_rad = degToRad(latitude);
        const long double lat_sin = sin(lat_rad);
        const long double lat_cos = cos(lat_rad);

        const long double lat_tan = lat_sin / lat_cos;
        const long double lat_tan2 = lat_tan * lat_tan;
        const long double lat_tan4 = lat_tan2 * lat_tan2;

        const int zone_number = latlon_to_zone_number(latitude, longitude);
        const char zone_letter = latitude_to_zone_letter(latitude);

        const long double lon_rad = degToRad(longitude);
        const long double central_lon = zone_number_to_central_longitude(zone_number);
        const long double central_lon_rad = degToRad(central_lon);

        const long double n = R / sqrt(1.0 - E * pow(lat_sin, 2.0));
        const long double c = E_P2 * pow(lat_cos, 2.0);

        const long double a = lat_cos * (lon_rad - central_lon_rad);
        const long double a2 = a * a;
        const long double a3 = a2 * a;
        const long double a4 = a3 * a;
        const long double a5 = a4 * a;
        const long double a6 = a5 * a;

        const long double m = R * (M1 * lat_rad - M2 * sin(2 * lat_rad) + M3 * sin(4 * lat_rad) - M4 * sin(6 * lat_rad));

        long double easting = K0 * n * (a + a3 / 6 * (1 - lat_tan2 + c) + a5 / 120 * (5 - 18 * lat_tan2 + lat_tan4 + 72 * c - 58 * E_P2)) + 500000;
        long double northing = K0 * (m + n * lat_tan * (a2 / 2 + a4 / 24 * (5 - lat_tan2 + 9 * c + 4 * pow(c, 2)) + a6 / 720 * (61 - 58 * lat_tan2 + lat_tan4 + 600 * c - 330 * E_P2)));

        if (latitude < 0) {
            northing += 10000000;
        }

        cache::zone_number = zone_number;
        cache::zone_letter = zone_letter;
        return {easting, northing, zone_number, zone_letter};
    }

} // utm
} // libuuas
