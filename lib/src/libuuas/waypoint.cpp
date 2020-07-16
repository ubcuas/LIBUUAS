#include "libuuas/waypoint.hpp"

std::vector<Waypoint> draw_full_route(std::Vector<Waypoint> input_waypoints, std::Vector<CylinderObstacle> input_obstacles, Flyzone input_flyzone) {
    std::vector<Waypoint> auto_flight_wps;
    Waypoint airdrop_wp;
    Waypoint off_axis_wp;
    std::vector<Waypoint> search_grid_bounds;

    for (auto Waypoint: input_waypoints) {
        switch (Waypoint.waypoint_type()) {
            case WaypointType::AUTO_FLIGHT:
                auto_flight_wps.push_back(Waypoint);
                break;
            case WaypointType::AIRDROP:
                airdrop_wp = Waypoint;
                break;
            case WaypointType::OFF_AXIS:
                off_axis_wp = Waypoint;
                break;
            case WaypointType::SEARCH_GRID:
                search_grid_bounds.push_back(Waypoint);
                break;
            default:
                break;
        }
    }

    SearchGrid search_grid (search_grid_bounds, input_flyzone);

    Map auto_flight_map = Map(auto_flight_wps, input_obstacles, input_flyzone);
    auto_flight_route = auto_flight_map.generateOrderedRoute();
}

Map::Map(std::vector<Waypoint> ordered_wps, std::Vector<CylinderObstacle> obstacles, Flyzone flyzone): _ordered_wps(ordered_wps)
