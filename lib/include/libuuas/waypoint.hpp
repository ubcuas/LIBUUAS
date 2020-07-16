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
    GENERATED,
    AUTO_FLIGHT,
    AIRDROP,
    OFF_AXIS,
    SEARCH_GRID,
};

class Waypoint: public Coordinate {
public:
    Waypoint(double latitude, double longitude, double altitude_msl_m, WaypointType waypoint_type);

    WaypointType waypoint_type();
};

class Flyzone {
public:
    Flyzone(std::vector<Coordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m);
}

class SearchGrid {
public:
    SearchGrid(std::vector<Coordinate> bounds, Flyzone flyzone);
}

class Map {
public:
    Map(std::vector<Waypoint> ordered_wps, std::Vector<CylinderObstacle> obstacles, Flyzone flyzone);
    std::vector<Waypoint> generateOrderedRoute();

private:
    std::vector<Waypoint> _ordered_wps;
    std::vector<CylinderObstacle> _obstacles;
    Flyzone _flyzone;
}
