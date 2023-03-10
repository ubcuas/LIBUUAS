# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: uuaspb.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='uuaspb.proto',
  package='uuaspb',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0cuuaspb.proto\x12\x06uuaspb\"G\n\rGeoTagRequest\x12\x10\n\x08\x66ilename\x18\x01 \x01(\t\x12$\n\ttelemetry\x18\x02 \x01(\x0b\x32\x11.uuaspb.Telemetry\"6\n\x0eGeoTagResponse\x12$\n\x06result\x18\x01 \x01(\x0e\x32\x14.uuaspb.ResultStatus\"#\n\x0fUnGeoTagRequest\x12\x10\n\x08\x66ilename\x18\x01 \x01(\t\"^\n\x10UnGeoTagResponse\x12$\n\x06result\x18\x01 \x01(\x0e\x32\x14.uuaspb.ResultStatus\x12$\n\ttelemetry\x18\x02 \x01(\x0b\x32\x11.uuaspb.Telemetry\"\xff\x02\n\tTelemetry\x12\x16\n\x0elatitude_dege7\x18\x01 \x01(\x05\x12\x17\n\x0flongitude_dege7\x18\x02 \x01(\x05\x12\x16\n\x0e\x61ltitude_agl_m\x18\x03 \x01(\x01\x12\x16\n\x0e\x61ltitude_msl_m\x18\x04 \x01(\x01\x12\x13\n\x0bheading_deg\x18\x05 \x01(\x01\x12\x15\n\rvelocityx_m_s\x18\x06 \x01(\x01\x12\x15\n\rvelocityy_m_s\x18\x07 \x01(\x01\x12\x15\n\rvelocityz_m_s\x18\x08 \x01(\x01\x12\x10\n\x08roll_rad\x18\t \x01(\x01\x12\x11\n\tpitch_rad\x18\n \x01(\x01\x12\x0f\n\x07yaw_rad\x18\x0b \x01(\x01\x12\x17\n\x0frollspeed_rad_s\x18\x0c \x01(\x01\x12\x18\n\x10pitchspeed_rad_s\x18\r \x01(\x01\x12\x16\n\x0eyawspeed_rad_s\x18\x0e \x01(\x01\x12\x1c\n\x14timestamp_pixhawk_ms\x18\x0f \x01(\x04\x12\x18\n\x10timestamp_msg_ms\x18\x10 \x01(\x04\"\x89\x01\n\x13OrderedRouteRequest\x12#\n\twaypoints\x18\x01 \x03(\x0b\x32\x10.uuaspb.Waypoint\x12+\n\tobstacles\x18\x02 \x03(\x0b\x32\x18.uuaspb.CylinderObstacle\x12 \n\x07\x66lyzone\x18\x03 \x01(\x0b\x32\x0f.uuaspb.Flyzone\"a\n\x14OrderedRouteResponse\x12$\n\x06result\x18\x01 \x01(\x0e\x32\x14.uuaspb.ResultStatus\x12#\n\twaypoints\x18\x02 \x03(\x0b\x32\x10.uuaspb.Waypoint\"h\n\x07\x46lyzone\x12\x1a\n\x12max_altitude_msl_m\x18\x01 \x01(\x01\x12\x1a\n\x12min_altitude_msl_m\x18\x02 \x01(\x01\x12%\n\x06\x62ounds\x18\x03 \x03(\x0b\x32\x15.uuaspb.UasCoordinate\"@\n\rUasCoordinate\x12\x16\n\x0elatitude_dege7\x18\x01 \x01(\x05\x12\x17\n\x0flongitude_dege7\x18\x02 \x01(\x05\"z\n\x08Waypoint\x12)\n\ncoordinate\x18\x01 \x01(\x0b\x32\x15.uuaspb.UasCoordinate\x12\x16\n\x0e\x61ltitude_msl_m\x18\x02 \x01(\x01\x12+\n\rwaypoint_type\x18\x03 \x01(\x0e\x32\x14.uuaspb.WaypointType\"a\n\x10\x43ylinderObstacle\x12)\n\ncoordinate\x18\x01 \x01(\x0b\x32\x15.uuaspb.UasCoordinate\x12\x10\n\x08radius_m\x18\x02 \x01(\x01\x12\x10\n\x08height_m\x18\x03 \x01(\x01*\x1f\n\x0cResultStatus\x12\x06\n\x02OK\x10\x00\x12\x07\n\x03\x45RR\x10\x01*t\n\x0cWaypointType\x12\x08\n\x04NONE\x10\x00\x12\x0e\n\nCOORDINATE\x10\x01\x12\r\n\tGENERATED\x10\x02\x12\x0f\n\x0b\x41UTO_FLIGHT\x10\x03\x12\x0b\n\x07\x41IRDROP\x10\x04\x12\x0c\n\x08OFF_AXIS\x10\x05\x12\x0f\n\x0bSEARCH_GRID\x10\x06\x62\x06proto3'
)

_RESULTSTATUS = _descriptor.EnumDescriptor(
  name='ResultStatus',
  full_name='uuaspb.ResultStatus',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='OK', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='ERR', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=1306,
  serialized_end=1337,
)
_sym_db.RegisterEnumDescriptor(_RESULTSTATUS)

ResultStatus = enum_type_wrapper.EnumTypeWrapper(_RESULTSTATUS)
_WAYPOINTTYPE = _descriptor.EnumDescriptor(
  name='WaypointType',
  full_name='uuaspb.WaypointType',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='NONE', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='COORDINATE', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='GENERATED', index=2, number=2,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='AUTO_FLIGHT', index=3, number=3,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='AIRDROP', index=4, number=4,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='OFF_AXIS', index=5, number=5,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='SEARCH_GRID', index=6, number=6,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=1339,
  serialized_end=1455,
)
_sym_db.RegisterEnumDescriptor(_WAYPOINTTYPE)

WaypointType = enum_type_wrapper.EnumTypeWrapper(_WAYPOINTTYPE)
OK = 0
ERR = 1
NONE = 0
COORDINATE = 1
GENERATED = 2
AUTO_FLIGHT = 3
AIRDROP = 4
OFF_AXIS = 5
SEARCH_GRID = 6



_GEOTAGREQUEST = _descriptor.Descriptor(
  name='GeoTagRequest',
  full_name='uuaspb.GeoTagRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='filename', full_name='uuaspb.GeoTagRequest.filename', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='telemetry', full_name='uuaspb.GeoTagRequest.telemetry', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=24,
  serialized_end=95,
)


_GEOTAGRESPONSE = _descriptor.Descriptor(
  name='GeoTagResponse',
  full_name='uuaspb.GeoTagResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='uuaspb.GeoTagResponse.result', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=97,
  serialized_end=151,
)


_UNGEOTAGREQUEST = _descriptor.Descriptor(
  name='UnGeoTagRequest',
  full_name='uuaspb.UnGeoTagRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='filename', full_name='uuaspb.UnGeoTagRequest.filename', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=153,
  serialized_end=188,
)


_UNGEOTAGRESPONSE = _descriptor.Descriptor(
  name='UnGeoTagResponse',
  full_name='uuaspb.UnGeoTagResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='uuaspb.UnGeoTagResponse.result', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='telemetry', full_name='uuaspb.UnGeoTagResponse.telemetry', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=190,
  serialized_end=284,
)


_TELEMETRY = _descriptor.Descriptor(
  name='Telemetry',
  full_name='uuaspb.Telemetry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='latitude_dege7', full_name='uuaspb.Telemetry.latitude_dege7', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='longitude_dege7', full_name='uuaspb.Telemetry.longitude_dege7', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='altitude_agl_m', full_name='uuaspb.Telemetry.altitude_agl_m', index=2,
      number=3, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='altitude_msl_m', full_name='uuaspb.Telemetry.altitude_msl_m', index=3,
      number=4, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='heading_deg', full_name='uuaspb.Telemetry.heading_deg', index=4,
      number=5, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='velocityx_m_s', full_name='uuaspb.Telemetry.velocityx_m_s', index=5,
      number=6, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='velocityy_m_s', full_name='uuaspb.Telemetry.velocityy_m_s', index=6,
      number=7, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='velocityz_m_s', full_name='uuaspb.Telemetry.velocityz_m_s', index=7,
      number=8, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='roll_rad', full_name='uuaspb.Telemetry.roll_rad', index=8,
      number=9, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='pitch_rad', full_name='uuaspb.Telemetry.pitch_rad', index=9,
      number=10, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='yaw_rad', full_name='uuaspb.Telemetry.yaw_rad', index=10,
      number=11, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='rollspeed_rad_s', full_name='uuaspb.Telemetry.rollspeed_rad_s', index=11,
      number=12, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='pitchspeed_rad_s', full_name='uuaspb.Telemetry.pitchspeed_rad_s', index=12,
      number=13, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='yawspeed_rad_s', full_name='uuaspb.Telemetry.yawspeed_rad_s', index=13,
      number=14, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='timestamp_pixhawk_ms', full_name='uuaspb.Telemetry.timestamp_pixhawk_ms', index=14,
      number=15, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='timestamp_msg_ms', full_name='uuaspb.Telemetry.timestamp_msg_ms', index=15,
      number=16, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=287,
  serialized_end=670,
)


_ORDEREDROUTEREQUEST = _descriptor.Descriptor(
  name='OrderedRouteRequest',
  full_name='uuaspb.OrderedRouteRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='waypoints', full_name='uuaspb.OrderedRouteRequest.waypoints', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='obstacles', full_name='uuaspb.OrderedRouteRequest.obstacles', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='flyzone', full_name='uuaspb.OrderedRouteRequest.flyzone', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=673,
  serialized_end=810,
)


_ORDEREDROUTERESPONSE = _descriptor.Descriptor(
  name='OrderedRouteResponse',
  full_name='uuaspb.OrderedRouteResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='uuaspb.OrderedRouteResponse.result', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='waypoints', full_name='uuaspb.OrderedRouteResponse.waypoints', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=812,
  serialized_end=909,
)


_FLYZONE = _descriptor.Descriptor(
  name='Flyzone',
  full_name='uuaspb.Flyzone',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='max_altitude_msl_m', full_name='uuaspb.Flyzone.max_altitude_msl_m', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='min_altitude_msl_m', full_name='uuaspb.Flyzone.min_altitude_msl_m', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='bounds', full_name='uuaspb.Flyzone.bounds', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=911,
  serialized_end=1015,
)


_UASCOORDINATE = _descriptor.Descriptor(
  name='UasCoordinate',
  full_name='uuaspb.UasCoordinate',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='latitude_dege7', full_name='uuaspb.UasCoordinate.latitude_dege7', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='longitude_dege7', full_name='uuaspb.UasCoordinate.longitude_dege7', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1017,
  serialized_end=1081,
)


_WAYPOINT = _descriptor.Descriptor(
  name='Waypoint',
  full_name='uuaspb.Waypoint',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='coordinate', full_name='uuaspb.Waypoint.coordinate', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='altitude_msl_m', full_name='uuaspb.Waypoint.altitude_msl_m', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='waypoint_type', full_name='uuaspb.Waypoint.waypoint_type', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1083,
  serialized_end=1205,
)


_CYLINDEROBSTACLE = _descriptor.Descriptor(
  name='CylinderObstacle',
  full_name='uuaspb.CylinderObstacle',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='coordinate', full_name='uuaspb.CylinderObstacle.coordinate', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='radius_m', full_name='uuaspb.CylinderObstacle.radius_m', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='height_m', full_name='uuaspb.CylinderObstacle.height_m', index=2,
      number=3, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=1207,
  serialized_end=1304,
)

_GEOTAGREQUEST.fields_by_name['telemetry'].message_type = _TELEMETRY
_GEOTAGRESPONSE.fields_by_name['result'].enum_type = _RESULTSTATUS
_UNGEOTAGRESPONSE.fields_by_name['result'].enum_type = _RESULTSTATUS
_UNGEOTAGRESPONSE.fields_by_name['telemetry'].message_type = _TELEMETRY
_ORDEREDROUTEREQUEST.fields_by_name['waypoints'].message_type = _WAYPOINT
_ORDEREDROUTEREQUEST.fields_by_name['obstacles'].message_type = _CYLINDEROBSTACLE
_ORDEREDROUTEREQUEST.fields_by_name['flyzone'].message_type = _FLYZONE
_ORDEREDROUTERESPONSE.fields_by_name['result'].enum_type = _RESULTSTATUS
_ORDEREDROUTERESPONSE.fields_by_name['waypoints'].message_type = _WAYPOINT
_FLYZONE.fields_by_name['bounds'].message_type = _UASCOORDINATE
_WAYPOINT.fields_by_name['coordinate'].message_type = _UASCOORDINATE
_WAYPOINT.fields_by_name['waypoint_type'].enum_type = _WAYPOINTTYPE
_CYLINDEROBSTACLE.fields_by_name['coordinate'].message_type = _UASCOORDINATE
DESCRIPTOR.message_types_by_name['GeoTagRequest'] = _GEOTAGREQUEST
DESCRIPTOR.message_types_by_name['GeoTagResponse'] = _GEOTAGRESPONSE
DESCRIPTOR.message_types_by_name['UnGeoTagRequest'] = _UNGEOTAGREQUEST
DESCRIPTOR.message_types_by_name['UnGeoTagResponse'] = _UNGEOTAGRESPONSE
DESCRIPTOR.message_types_by_name['Telemetry'] = _TELEMETRY
DESCRIPTOR.message_types_by_name['OrderedRouteRequest'] = _ORDEREDROUTEREQUEST
DESCRIPTOR.message_types_by_name['OrderedRouteResponse'] = _ORDEREDROUTERESPONSE
DESCRIPTOR.message_types_by_name['Flyzone'] = _FLYZONE
DESCRIPTOR.message_types_by_name['UasCoordinate'] = _UASCOORDINATE
DESCRIPTOR.message_types_by_name['Waypoint'] = _WAYPOINT
DESCRIPTOR.message_types_by_name['CylinderObstacle'] = _CYLINDEROBSTACLE
DESCRIPTOR.enum_types_by_name['ResultStatus'] = _RESULTSTATUS
DESCRIPTOR.enum_types_by_name['WaypointType'] = _WAYPOINTTYPE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

GeoTagRequest = _reflection.GeneratedProtocolMessageType('GeoTagRequest', (_message.Message,), {
  'DESCRIPTOR' : _GEOTAGREQUEST,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.GeoTagRequest)
  })
_sym_db.RegisterMessage(GeoTagRequest)

GeoTagResponse = _reflection.GeneratedProtocolMessageType('GeoTagResponse', (_message.Message,), {
  'DESCRIPTOR' : _GEOTAGRESPONSE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.GeoTagResponse)
  })
_sym_db.RegisterMessage(GeoTagResponse)

UnGeoTagRequest = _reflection.GeneratedProtocolMessageType('UnGeoTagRequest', (_message.Message,), {
  'DESCRIPTOR' : _UNGEOTAGREQUEST,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.UnGeoTagRequest)
  })
_sym_db.RegisterMessage(UnGeoTagRequest)

UnGeoTagResponse = _reflection.GeneratedProtocolMessageType('UnGeoTagResponse', (_message.Message,), {
  'DESCRIPTOR' : _UNGEOTAGRESPONSE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.UnGeoTagResponse)
  })
_sym_db.RegisterMessage(UnGeoTagResponse)

Telemetry = _reflection.GeneratedProtocolMessageType('Telemetry', (_message.Message,), {
  'DESCRIPTOR' : _TELEMETRY,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.Telemetry)
  })
_sym_db.RegisterMessage(Telemetry)

OrderedRouteRequest = _reflection.GeneratedProtocolMessageType('OrderedRouteRequest', (_message.Message,), {
  'DESCRIPTOR' : _ORDEREDROUTEREQUEST,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.OrderedRouteRequest)
  })
_sym_db.RegisterMessage(OrderedRouteRequest)

OrderedRouteResponse = _reflection.GeneratedProtocolMessageType('OrderedRouteResponse', (_message.Message,), {
  'DESCRIPTOR' : _ORDEREDROUTERESPONSE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.OrderedRouteResponse)
  })
_sym_db.RegisterMessage(OrderedRouteResponse)

Flyzone = _reflection.GeneratedProtocolMessageType('Flyzone', (_message.Message,), {
  'DESCRIPTOR' : _FLYZONE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.Flyzone)
  })
_sym_db.RegisterMessage(Flyzone)

UasCoordinate = _reflection.GeneratedProtocolMessageType('UasCoordinate', (_message.Message,), {
  'DESCRIPTOR' : _UASCOORDINATE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.UasCoordinate)
  })
_sym_db.RegisterMessage(UasCoordinate)

Waypoint = _reflection.GeneratedProtocolMessageType('Waypoint', (_message.Message,), {
  'DESCRIPTOR' : _WAYPOINT,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.Waypoint)
  })
_sym_db.RegisterMessage(Waypoint)

CylinderObstacle = _reflection.GeneratedProtocolMessageType('CylinderObstacle', (_message.Message,), {
  'DESCRIPTOR' : _CYLINDEROBSTACLE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuaspb.CylinderObstacle)
  })
_sym_db.RegisterMessage(CylinderObstacle)


# @@protoc_insertion_point(module_scope)
