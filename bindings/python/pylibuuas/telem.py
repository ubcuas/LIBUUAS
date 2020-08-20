import pylibuuas.uuaspb_pb2 as pylibuuaspb
import collections

TelemetryArgs = collections.namedtuple(
    'TelemetryArgs',
    [
        'latitude',
        'longitude',
        'altitude_agl_m',
        'altitude_msl_m',
        'heading_deg',
        'velocityx_m_s',
        'velocityy_m_s',
        'velocityz_m_s',
        'roll_rad',
        'pitch_rad',
        'yaw_rad',
        'rollspeed_rad_s',
        'pitchspeed_rad_s',
        'yawspeed_rad_s',
        'timestamp_pixhawk_ms',
        'timestamp_msg_ms',
    ]
)


def new_telem_msg(args: TelemetryArgs) -> pylibuuaspb.Telemetry:
    msg = pylibuuaspb.Telemetry()
    msg.latitude = args.latitude
    msg.longitude = args.longitude
    msg.altitude_agl_m = args.altitude_agl_m
    msg.altitude_msl_m = args.altitude_msl_m
    msg.heading_deg = args.heading_deg
    msg.velocityx_m_s = args.velocityx_m_s
    msg.velocityy_m_s = args.velocityy_m_s
    msg.velocityz_m_s = args.velocityz_m_s
    msg.roll_rad = args.roll_rad
    msg.pitch_rad = args.pitch_rad
    msg.yaw_rad = args.yaw_rad
    msg.rollspeed_rad_s = args.rollspeed_rad_s
    msg.pitchspeed_rad_s = args.pitchspeed_rad_s
    msg.yawspeed_rad_s = args.yawspeed_rad_s
    msg.timestamp_pixhawk_ms = args.timestamp_pixhawk_ms
    msg.timestamp_msg_ms = args.timestamp_msg_ms
    return msg


def serialize_telem_msg(msg: pylibuuaspb.Telemetry) -> str:
    return pylibuuaspb.Telemetry.SerializeToString(msg)


def deserialize_telem_msg(buffer: str) -> pylibuuaspb.Telemetry:
    message = pylibuuaspb.Telemetry()
    message.ParseFromString(buffer)
    return message
