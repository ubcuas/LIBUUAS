#include <vector>

class Coordinate {
    Coordinate(double latitude, double longitude);

    double latitude();
    double longitude();
    double easting_m();
    double northing_m();

private:
    double _latitude;
    double _longitude;
};

class CylinderObstacle: public Coordinate {
public:
    CylinderObstacle(double latitude, double longitude, double radius_m, double height_m);

    double radius_m();
    double height_m();

private:
    double _radius_m;
    double _height_m;
};

enum class WaypointType {
    NONE,
    AUTO_FLIGHT,
    AIRDROP,
    SEARCH_GRID,
    OFF_AXIS,
};

class Waypoint: public Coordinate {
public:
    Waypoint(double latitude, double longitude, double altitude_msl_m, bool generated, WaypointType waypoint_type);
};

class Flyzone {
public:
    Flyzone(std::std::vector<Coordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m);
}
