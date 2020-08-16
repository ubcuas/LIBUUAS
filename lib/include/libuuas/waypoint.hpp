#pragma once

#include <geos/geom/Coordinate.h>
#include <geos/geom/CoordinateArraySequence.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/LinearRing.h>
#include <geos/geom/Point.h>
#include <geos/geom/Polygon.h>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

namespace libuuas {
namespace geost {
    using coord = geos::geom::Coordinate;
    using coordArray = geos::geom::CoordinateArraySequence;
    using coordSeq = geos::geom::CoordinateSequence;
    using geom = geos::geom::Geometry;
    using geomFactoryUPtr = geos::geom::GeometryFactory::unique_ptr;
    using geomUPtr = std::unique_ptr<geos::geom::Geometry>;
    using linearRing = geos::geom::LinearRing;
    using linearRingUPtr = std::unique_ptr<geos::geom::LinearRing>;
    using lineString = geos::geom::LineString;
    using point = geos::geom::Point;
    using pointUPtr = std::unique_ptr<geos::geom::Point>;
    using poly = geos::geom::Polygon;
    using polyUPtr = std::unique_ptr<geos::geom::Polygon>;
} // namespace geost
} // namespace libuuas

namespace libuuas {
namespace waypointing {

    constexpr int safetyMargin_m = 10;

    class UasCoordinate {
    public:
        UasCoordinate();
        UasCoordinate(double latitude, double longitude);
        UasCoordinate(geos::geom::Coordinate geosCoord);
        UasCoordinate(geos::geom::Coordinate geosCoord, int zoneNumber, char zoneLetter);

        geos::geom::Coordinate asGeosCoordinate() const;
        std::unique_ptr<geos::geom::Point> asGeosPoint() const;

        double latitude() const;
        double longitude() const;
        double easting_m() const;
        double northing_m() const;

    private:
        double _latitude;
        double _longitude;
        double _easting_m;
        double _northing_m;
        int _zone_number;
        int _zone_letter;
    };

    class CylinderObstacle : public UasCoordinate {
    public:
        CylinderObstacle(double latitude, double longitude, double radius_m, double height_m);

        std::vector<UasCoordinate> pointsOfInterest();
        std::unique_ptr<geos::geom::Geometry> asGeosGeom();

        double radius_m();
        double height_m();

    private:
        double _radius_m;
        double _height_m;
    };

    enum class WaypointType {
        NONE,
        COORDINATE,
        GENERATED,
        AUTO_FLIGHT,
        AIRDROP,
        OFF_AXIS,
        SEARCH_GRID,
    };

    class Waypoint : public UasCoordinate {
    public:
        Waypoint();
        Waypoint(UasCoordinate coord, double altitude_msl_m, WaypointType waypoint_type);
        Waypoint(double latitude, double longitude, double altitude_msl_m, WaypointType waypoint_type);

        UasCoordinate asUasCoordinate() const;

        double altitude_msl_m() const;
        WaypointType waypoint_type() const;

    private:
        double _altitude_msl_m;
        WaypointType _waypoint_type;
    };

    bool operator==(const Waypoint& a, const Waypoint& b);
    bool operator!=(const Waypoint& a, const Waypoint& b);

    class Flyzone {
    public:
        Flyzone();
        Flyzone(std::vector<UasCoordinate> bounds, double max_altitude_msl_m, double min_altitude_msl_m);

        std::vector<UasCoordinate> pointsOfInterest();
        std::unique_ptr<geos::geom::LinearRing> asGeosLinearRing();
        std::unique_ptr<geos::geom::Polygon> asGeosPoly();
        bool isCoordWithinFlyzone(UasCoordinate uasCoord);
        bool isCoordWithinFlyzone(std::unique_ptr<geos::geom::Point> point);

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
        std::vector<Waypoint> shortestRoute(Waypoint start, Waypoint end);
        std::vector<Waypoint> shortestRoute(std::vector<Waypoint> waypoints);

        bool isCoordWithinFlyzone(UasCoordinate uasCoord);

        int distance(UasCoordinate start, UasCoordinate end);

        bool validRoute(Waypoint start, Waypoint end);
        bool validRoute(Waypoint start, UasCoordinate end);
        bool validRoute(UasCoordinate start, UasCoordinate end);
        bool validRoute(UasCoordinate* start, UasCoordinate* end);

    private:
        void generatePointsOfInterests();

        std::unordered_map<size_t, std::vector<size_t>> _wpoi_connections;
        std::vector<UasCoordinate> _flyable_wpoi;

        std::vector<Waypoint> _ordered_wps;
        std::vector<CylinderObstacle> _obstacles;
        Flyzone _flyzone;
    };

} // namespace waypointing
} // namespace libuuas
