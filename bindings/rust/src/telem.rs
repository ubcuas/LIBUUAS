use protobuf;
use std::boxed::Box;

use super::uuaspb;

#[derive(Debug, Default, Clone)]
pub struct MavlinkTelemetryArgs {
    pub latitude: i32,
    pub longitude: i32,
    pub altitude_agl_mm: i32,
    pub altitude_msl_mm: i32,
    pub heading_cdeg: u16,
    pub velocityx_cm_s: i16,
    pub velocityy_cm_s: i16,
    pub velocityz_cm_s: i16,
    pub roll_rad: f32,
    pub pitch_rad: f32,
    pub yaw_rad: f32,
    pub rollspeed_rad_s: f32,
    pub pitchspeed_rad_s: f32,
    pub yawspeed_rad_s: f32,
    pub timestamp_pixhawk_ms: u32,
    pub timestamp_msg_ms: u64,
}

#[derive(Debug, Default, Clone)]
pub struct TelemetryArgs {
    pub latitude: f64,
    pub longitude: f64,
    pub altitude_agl_m: f64,
    pub altitude_msl_m: f64,
    pub heading_deg: f64,
    pub velocityx_m_s: f64,
    pub velocityy_m_s: f64,
    pub velocityz_m_s: f64,
    pub roll_rad: f64,
    pub pitch_rad: f64,
    pub yaw_rad: f64,
    pub rollspeed_rad_s: f64,
    pub pitchspeed_rad_s: f64,
    pub yawspeed_rad_s: f64,
    pub timestamp_pixhawk_ms: u64,
    pub timestamp_msg_ms: u64,
}

impl TelemetryArgs {
    pub fn from_mavlinkargs(mav_args: MavlinkTelemetryArgs) -> TelemetryArgs {
        return TelemetryArgs {
            latitude: mav_args.latitude as f64 / 1.0E7,
            longitude: mav_args.longitude as f64 / 1.0E7,
            altitude_agl_m: mav_args.altitude_agl_mm as f64 / 1000.0,
            altitude_msl_m: mav_args.altitude_msl_mm as f64 / 1000.0,
            heading_deg: mav_args.heading_cdeg as f64 / 100.0,
            velocityx_m_s: mav_args.velocityx_cm_s as f64 / 100.0,
            velocityy_m_s: mav_args.velocityy_cm_s as f64 / 100.0,
            velocityz_m_s: mav_args.velocityz_cm_s as f64 / 100.0,
            roll_rad: mav_args.roll_rad as f64,
            pitch_rad: mav_args.pitch_rad as f64,
            yaw_rad: mav_args.yaw_rad as f64,
            rollspeed_rad_s: mav_args.rollspeed_rad_s as f64,
            pitchspeed_rad_s: mav_args.pitchspeed_rad_s as f64,
            yawspeed_rad_s: mav_args.yawspeed_rad_s as f64,
            timestamp_pixhawk_ms: mav_args.timestamp_pixhawk_ms as u64,
            timestamp_msg_ms: mav_args.timestamp_msg_ms,
        };
    }
}

pub fn new_telem_msg(args: TelemetryArgs) -> uuaspb::Telemetry {
    let mut msg = uuaspb::Telemetry::new();
    msg.latitude = args.latitude;
    msg.longitude = args.longitude;
    msg.altitude_agl_m = args.altitude_agl_m;
    msg.altitude_msl_m = args.altitude_msl_m;
    msg.heading_deg = args.heading_deg;
    msg.velocityx_m_s = args.velocityx_m_s;
    msg.velocityy_m_s = args.velocityy_m_s;
    msg.velocityz_m_s = args.velocityz_m_s;
    msg.roll_rad = args.roll_rad;
    msg.pitch_rad = args.pitch_rad;
    msg.yaw_rad = args.yaw_rad;
    msg.rollspeed_rad_s = args.rollspeed_rad_s;
    msg.pitchspeed_rad_s = args.pitchspeed_rad_s;
    msg.yawspeed_rad_s = args.yawspeed_rad_s;
    msg.timestamp_pixhawk_ms = args.timestamp_pixhawk_ms;
    msg.timestamp_msg_ms = args.timestamp_msg_ms;
    return msg;
}

pub fn write_msg_to_args(args: &mut TelemetryArgs, msg: uuaspb::Telemetry) {
    args.latitude = msg.latitude;
    args.longitude = msg.longitude;
    args.altitude_agl_m = msg.altitude_agl_m;
    args.altitude_msl_m = msg.altitude_msl_m;
    args.heading_deg = msg.heading_deg;
    args.velocityx_m_s = msg.velocityx_m_s;
    args.velocityy_m_s = msg.velocityy_m_s;
    args.velocityz_m_s = msg.velocityz_m_s;
    args.roll_rad = msg.roll_rad;
    args.pitch_rad = msg.pitch_rad;
    args.yaw_rad = msg.yaw_rad;
    args.rollspeed_rad_s = msg.rollspeed_rad_s;
    args.pitchspeed_rad_s = msg.pitchspeed_rad_s;
    args.yawspeed_rad_s = msg.yawspeed_rad_s;
    args.timestamp_pixhawk_ms = msg.timestamp_pixhawk_ms;
    args.timestamp_msg_ms = msg.timestamp_msg_ms;
}

pub fn serialize_telem_msg(msg: uuaspb::Telemetry) -> Vec<u8> {
    let boxedmsg: Box<dyn protobuf::Message> = Box::new(msg);
    let buffer: Vec<u8> = boxedmsg.write_to_bytes().unwrap();
    return buffer;
}

pub fn deserialize_telem_msg(
    buffer: &[u8],
) -> Result<uuaspb::Telemetry, Box<dyn std::error::Error>> {
    let msg = protobuf::parse_from_bytes(buffer)?;
    return Ok(msg);
}
