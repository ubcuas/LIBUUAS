use protobuf;
use std::boxed::Box;

use super::uuaspb;

pub struct TelemetryArgs {
    pub latitude: i32,
    pub longitude: i32,
    pub altitude_agl_meters: i32,
    pub altitude_msl_meters: i32,
    pub heading_degrees: u32,
    pub velocity_x_cm_s: i32,
    pub velocity_y_cm_s: i32,
    pub velocity_z_cm_s: i32,
    pub roll_rad: f64,
    pub pitch_rad: f64,
    pub yaw_rad: f64,
    pub rollspeed_rad_s: f64,
    pub pitchspeed_rad_s: f64,
    pub yawspeed_rad_s: f64,
    pub timestamp_telem_ms: u64,
    pub timestamp_msg_ms: u64,
}

pub fn new_telem_msg(args: TelemetryArgs) -> uuaspb::Telemetry {
    let mut msg = uuaspb::Telemetry::new();
    msg.latitude = args.latitude;
    msg.longitude = args.longitude;
    msg.altitude_agl_meters = args.altitude_agl_meters;
    msg.altitude_msl_meters = args.altitude_msl_meters;
    msg.heading_degrees = args.heading_degrees;
    msg.velocity_x_cm_s = args.velocity_x_cm_s;
    msg.velocity_y_cm_s = args.velocity_y_cm_s;
    msg.velocity_z_cm_s = args.velocity_z_cm_s;
    msg.roll_rad = args.roll_rad;
    msg.pitch_rad = args.pitch_rad;
    msg.yaw_rad = args.yaw_rad;
    msg.rollspeed_rad_s = args.rollspeed_rad_s;
    msg.pitchspeed_rad_s = args.pitchspeed_rad_s;
    msg.yawspeed_rad_s = args.yawspeed_rad_s;
    msg.timestamp_telem_ms = args.timestamp_telem_ms;
    msg.timestamp_msg_ms = args.timestamp_msg_ms;
    return msg;
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
