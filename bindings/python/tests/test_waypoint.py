import pytest
import shutil
import os

from pylibuuas.waypoint import *


@pytest.fixture
def test_flyzone():
    bounds = [
        UasCoordinate(latitude=38.153364, longitude=-76.436760),
        UasCoordinate(latitude=38.148429, longitude=-76.417743),
        UasCoordinate(latitude=38.140846, longitude=-76.423239),
        UasCoordinate(latitude=38.141798, longitude=-76.435273),
    ]
    flyzone = Flyzone(
        max_altitude_msl_m=100,
        min_altitude_msl_m=0,
        bounds=bounds,
    )
    return flyzone


@pytest.fixture
def test_single_obstacle():
    coord = UasCoordinate(latitude=38.144692, longitude=-76.427995)
    obs = CylinderObstacle(coordinate=coord, radius_m=25, height_m=70)
    return [obs]


@pytest.fixture
def test_single_wp_segment():
    start_coord = UasCoordinate(latitude=38.143665, longitude=-76.426940)
    start_wp = Waypoint(coordinate=start_coord, altitude_msl_m=35,
                        waypoint_type=WaypointType.AUTO_FLIGHT)

    end_coord = UasCoordinate(latitude=38.146276, longitude=-76.429538)
    end_wp = Waypoint(coordinate=end_coord, altitude_msl_m=35,
                      waypoint_type=WaypointType.AUTO_FLIGHT)
    return [start_wp, end_wp]


def test_orderedRoute(test_single_wp_segment, test_single_obstacle, test_flyzone):
    results = orderedRoute(test_single_wp_segment,
                           test_single_obstacle, test_flyzone)
    assert len(results) == 3
