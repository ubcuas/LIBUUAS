import collections

from enum import Enum

import pylibuuas.uuaspb_pb2 as pylibuuaspb
import pylibuuas.libuuas as libuuas


class WaypointType(Enum):
    NONE = 0
    COORDINATE = 1
    GENERATED = 2
    AUTO_FLIGHT = 3
    AIRDROP = 4
    OFF_AXIS = 5
    SEARCH_GRID = 6

    def toProtobuf(self):
        if self.name == 'NONE':
            return pylibuuaspb.WaypointType.NONE
        if self.name == 'COORDINATE':
            return pylibuuaspb.WaypointType.COORDINATE
        if self.name == 'GENERATED':
            return pylibuuaspb.WaypointType.GENERATED
        if self.name == 'AUTO_FLIGHT':
            return pylibuuaspb.WaypointType.AUTO_FLIGHT
        if self.name == 'AIRDROP':
            return pylibuuaspb.WaypointType.AIRDROP
        if self.name == 'OFF_AXIS':
            return pylibuuaspb.WaypointType.OFF_AXIS
        if self.name == 'SEARCH_GRID':
            return pylibuuaspb.WaypointType.SEARCH_GRID

Flyzone = collections.namedtuple(
    'Flyzone',
    [
        'max_altitude_msl_m',
        'min_altitude_msl_m',
        'bounds',
    ]
)

UasCoordinate = collections.namedtuple(
    'UasCoordinate',
    [
        'latitude',
        'longitude',
    ]
)

Waypoint = collections.namedtuple(
    'Waypoint',
    [
        'coordinate',
        'altitude_msl_m',
        'waypoint_type',
    ]
)

CylinderObstacle = collections.namedtuple(
    'CylinderObstacle',
    [
        'coordinate',
        'radius_m',
        'height_m',
    ]
)


def orderedRoute(waypoints: [Waypoint], obstacles: [CylinderObstacle], flyzone: Flyzone) -> [Waypoint]:
    request = pylibuuaspb.OrderedRouteRequest()
    for waypoint in waypoints:
        pbWaypoint = request.waypoints.add()
        pbWaypoint.coordinate.latitude = waypoint.coordinate.latitude
        pbWaypoint.coordinate.longitude = waypoint.coordinate.longitude
        pbWaypoint.altitude_msl_m = waypoint.altitude_msl_m
        pbWaypoint.waypoint_type = waypoint.waypoint_type.toProtobuf()

    for obstacle in obstacles:
        pbObstacle = request.obstacles.add()
        pbObstacle.coordinate.latitude = obstacle.coordinate.latitude
        pbObstacle.coordinate.longitude = obstacle.coordinate.longitude
        pbObstacle.radius_m = obstacle.radius_m
        pbObstacle.height_m = obstacle.height_m

    request.flyzone.max_altitude_msl_m = flyzone.max_altitude_msl_m
    request.flyzone.min_altitude_msl_m = flyzone.min_altitude_msl_m
    for bound in flyzone.bounds:
        pbBound = request.flyzone.bounds.add()
        pbBound.latitude = bound.latitude
        pbBound.longitude = bound.longitude

    response = libuuas.orderedRouteRequest(request)
    if response.result == pylibuuaspb.ResultStatus.OK:
        outputWaypoints = []
        for pbWaypoint in response.waypoints:
            coordinate = UasCoordinate(latitude=pbWaypoint.coordinate.latitude,
                                       longitude=pbWaypoint.coordinate.longitude)
            outputWaypoints.append(Waypoint(
                coordinate=coordinate, altitude_msl_m=pbWaypoint.altitude_msl_m, waypoint_type=pbWaypoint.waypoint_type))
        return outputWaypoints
    else:
        return []
