#include <geos/geom/Coordinate.h>
#include <vector>

constexpr int safetyMargin_m = 10;

class UasCoordinate {
public:
    UasCoordinate(double latitude, double longitude);
    UasCoordinate(geos::geom::Coordinate geosCoord);

    geos::geom::Coordinate asGeosCoordinate();

    double latitude();
    double longitude();
    double easting_m();
    double northing_m();

private:
    double _latitude;
    double _longitude;
};

class CylinderObstacle : public UasCoordinate {
public:
    CylinderObstacle(double latitude, double longitude, double radius_m, double height_m);

    std::vector<UasCoordinate> pointsOfInterest();

    double radius_m();
    double radius_m_unsafe();
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

class Waypoint : public UasCoordinate {
public:
    Waypoint();
    Waypoint(double latitude, double longitude, double altitude_msl_m, WaypointType waypoint_type);

    WaypointType waypoint_type();

private:
    double _altitude_msl_m;
    WaypointType _waypoint_type;
};

class Flyzone {
public:
    Flyzone();
    Flyzone(std::vector<UasCoordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m);

    std::vector<UasCoordinate> pointsOfInterest();

    double max_altitude_msl_m();
    double min_altitude_msl_m();

private:
    std::vector<UasCoordinate> _bounds;
    double _max_altitude_msl_m;
    double _min_altitude_msl_m;
};

class SearchGrid {
public:
    SearchGrid(std::vector<UasCoordinate> bounds, Flyzone flyzone);

private:
    std::vector<UasCoordinate> _bounds;
    Flyzone _flyzone;
};

class Map {
public:
    Map(std::vector<Waypoint> ordered_wps, std::vector<CylinderObstacle> obstacles, Flyzone flyzone);

    std::vector<Waypoint> generateOrderedRoute();

private:
    void generatePointsOfInterestMap();

    std::vector<UasCoordinate> _flyable_wpoi;

    std::vector<Waypoint> _ordered_wps;
    std::vector<CylinderObstacle> _obstacles;
    Flyzone _flyzone;
};
