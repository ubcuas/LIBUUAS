import pylibuuas.uuaspb_pb2 as pylibuuaspb
import collections

TelemetryArgs = collections.namedtuple(
    'TelemetryArgs',
    [
        'latitude',
        'longitude',
        'altitude_agl_meters',
        'altitude_msl_meters',
        'heading_degrees',
        'velocity_x_cm_s',
        'velocity_y_cm_s',
        'velocity_z_cm_s',
        'roll_rad',
        'pitch_rad',
        'yaw_rad',
        'rollspeed_rad_s',
        'pitchspeed_rad_s',
        'yawspeed_rad_s',
        'timestamp_telem_ms',
        'timestamp_msg_ms',
    ]
)


def new_telem_msg(args: TelemetryArgs) -> pylibuuaspb.Telemetry:
    msg = pylibuuaspb.Telemetry()
    msg.latitude = args.latitude
    msg.longitude = args.longitude
    msg.altitude_agl_meters = args.altitude_agl_meters
    msg.altitude_msl_meters = args.altitude_msl_meters
    msg.heading_degrees = args.heading_degrees
    msg.velocity_x_cm_s = args.velocity_x_cm_s
    msg.velocity_y_cm_s = args.velocity_y_cm_s
    msg.velocity_z_cm_s = args.velocity_z_cm_s
    msg.roll_rad = args.roll_rad
    msg.pitch_rad = args.pitch_rad
    msg.yaw_rad = args.yaw_rad
    msg.rollspeed_rad_s = args.rollspeed_rad_s
    msg.pitchspeed_rad_s = args.pitchspeed_rad_s
    msg.yawspeed_rad_s = args.yawspeed_rad_s
    msg.timestamp_telem_ms = args.timestamp_telem_ms
    msg.timestamp_msg_ms = args.timestamp_msg_ms
    return msg


def serialize_telem_msg(msg: pylibuuaspb.Telemetry) -> str:
    return pylibuuaspb.Telemetry.SerializeToString(msg)


def deserialize_telem_msg(buffer: str) -> pylibuuaspb.Telemetry:
    message = pylibuuaspb.Telemetry()
    message.ParseFromString(buffer)
    return message
