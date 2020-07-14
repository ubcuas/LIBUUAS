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
  package='uuas',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0cuuaspb.proto\x12\x04uuas\"E\n\rGeoTagRequest\x12\x10\n\x08\x66ilename\x18\x01 \x01(\t\x12\"\n\ttelemetry\x18\x02 \x01(\x0b\x32\x0f.uuas.Telemetry\"4\n\x0eGeoTagResponse\x12\"\n\x06result\x18\x01 \x01(\x0e\x32\x12.uuas.ResultStatus\"#\n\x0fUnGeoTagRequest\x12\x10\n\x08\x66ilename\x18\x01 \x01(\t\"Z\n\x10UnGeoTagResponse\x12\"\n\x06result\x18\x01 \x01(\x0e\x32\x12.uuas.ResultStatus\x12\"\n\ttelemetry\x18\x02 \x01(\x0b\x32\x0f.uuas.Telemetry\"\xf3\x02\n\tTelemetry\x12\x10\n\x08latitude\x18\x01 \x01(\x01\x12\x11\n\tlongitude\x18\x02 \x01(\x01\x12\x16\n\x0e\x61ltitude_agl_m\x18\x03 \x01(\x01\x12\x16\n\x0e\x61ltitude_msl_m\x18\x04 \x01(\x01\x12\x13\n\x0bheading_deg\x18\x05 \x01(\x01\x12\x15\n\rvelocityx_m_s\x18\x06 \x01(\x01\x12\x15\n\rvelocityy_m_s\x18\x07 \x01(\x01\x12\x15\n\rvelocityz_m_s\x18\x08 \x01(\x01\x12\x10\n\x08roll_rad\x18\t \x01(\x01\x12\x11\n\tpitch_rad\x18\n \x01(\x01\x12\x0f\n\x07yaw_rad\x18\x0b \x01(\x01\x12\x17\n\x0frollspeed_rad_s\x18\x0c \x01(\x01\x12\x18\n\x10pitchspeed_rad_s\x18\r \x01(\x01\x12\x16\n\x0eyawspeed_rad_s\x18\x0e \x01(\x01\x12\x1c\n\x14timestamp_pixhawk_ms\x18\x0f \x01(\x04\x12\x18\n\x10timestamp_msg_ms\x18\x10 \x01(\x04*\x1f\n\x0cResultStatus\x12\x06\n\x02OK\x10\x00\x12\x07\n\x03\x45RR\x10\x01\x62\x06proto3'
)

_RESULTSTATUS = _descriptor.EnumDescriptor(
  name='ResultStatus',
  full_name='uuas.ResultStatus',
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
  serialized_start=650,
  serialized_end=681,
)
_sym_db.RegisterEnumDescriptor(_RESULTSTATUS)

ResultStatus = enum_type_wrapper.EnumTypeWrapper(_RESULTSTATUS)
OK = 0
ERR = 1



_GEOTAGREQUEST = _descriptor.Descriptor(
  name='GeoTagRequest',
  full_name='uuas.GeoTagRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='filename', full_name='uuas.GeoTagRequest.filename', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='telemetry', full_name='uuas.GeoTagRequest.telemetry', index=1,
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
  serialized_start=22,
  serialized_end=91,
)


_GEOTAGRESPONSE = _descriptor.Descriptor(
  name='GeoTagResponse',
  full_name='uuas.GeoTagResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='uuas.GeoTagResponse.result', index=0,
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
  serialized_start=93,
  serialized_end=145,
)


_UNGEOTAGREQUEST = _descriptor.Descriptor(
  name='UnGeoTagRequest',
  full_name='uuas.UnGeoTagRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='filename', full_name='uuas.UnGeoTagRequest.filename', index=0,
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
  serialized_start=147,
  serialized_end=182,
)


_UNGEOTAGRESPONSE = _descriptor.Descriptor(
  name='UnGeoTagResponse',
  full_name='uuas.UnGeoTagResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='uuas.UnGeoTagResponse.result', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='telemetry', full_name='uuas.UnGeoTagResponse.telemetry', index=1,
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
  serialized_start=184,
  serialized_end=274,
)


_TELEMETRY = _descriptor.Descriptor(
  name='Telemetry',
  full_name='uuas.Telemetry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='latitude', full_name='uuas.Telemetry.latitude', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='longitude', full_name='uuas.Telemetry.longitude', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='altitude_agl_m', full_name='uuas.Telemetry.altitude_agl_m', index=2,
      number=3, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='altitude_msl_m', full_name='uuas.Telemetry.altitude_msl_m', index=3,
      number=4, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='heading_deg', full_name='uuas.Telemetry.heading_deg', index=4,
      number=5, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='velocityx_m_s', full_name='uuas.Telemetry.velocityx_m_s', index=5,
      number=6, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='velocityy_m_s', full_name='uuas.Telemetry.velocityy_m_s', index=6,
      number=7, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='velocityz_m_s', full_name='uuas.Telemetry.velocityz_m_s', index=7,
      number=8, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='roll_rad', full_name='uuas.Telemetry.roll_rad', index=8,
      number=9, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='pitch_rad', full_name='uuas.Telemetry.pitch_rad', index=9,
      number=10, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='yaw_rad', full_name='uuas.Telemetry.yaw_rad', index=10,
      number=11, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='rollspeed_rad_s', full_name='uuas.Telemetry.rollspeed_rad_s', index=11,
      number=12, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='pitchspeed_rad_s', full_name='uuas.Telemetry.pitchspeed_rad_s', index=12,
      number=13, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='yawspeed_rad_s', full_name='uuas.Telemetry.yawspeed_rad_s', index=13,
      number=14, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='timestamp_pixhawk_ms', full_name='uuas.Telemetry.timestamp_pixhawk_ms', index=14,
      number=15, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='timestamp_msg_ms', full_name='uuas.Telemetry.timestamp_msg_ms', index=15,
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
  serialized_start=277,
  serialized_end=648,
)

_GEOTAGREQUEST.fields_by_name['telemetry'].message_type = _TELEMETRY
_GEOTAGRESPONSE.fields_by_name['result'].enum_type = _RESULTSTATUS
_UNGEOTAGRESPONSE.fields_by_name['result'].enum_type = _RESULTSTATUS
_UNGEOTAGRESPONSE.fields_by_name['telemetry'].message_type = _TELEMETRY
DESCRIPTOR.message_types_by_name['GeoTagRequest'] = _GEOTAGREQUEST
DESCRIPTOR.message_types_by_name['GeoTagResponse'] = _GEOTAGRESPONSE
DESCRIPTOR.message_types_by_name['UnGeoTagRequest'] = _UNGEOTAGREQUEST
DESCRIPTOR.message_types_by_name['UnGeoTagResponse'] = _UNGEOTAGRESPONSE
DESCRIPTOR.message_types_by_name['Telemetry'] = _TELEMETRY
DESCRIPTOR.enum_types_by_name['ResultStatus'] = _RESULTSTATUS
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

GeoTagRequest = _reflection.GeneratedProtocolMessageType('GeoTagRequest', (_message.Message,), {
  'DESCRIPTOR' : _GEOTAGREQUEST,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuas.GeoTagRequest)
  })
_sym_db.RegisterMessage(GeoTagRequest)

GeoTagResponse = _reflection.GeneratedProtocolMessageType('GeoTagResponse', (_message.Message,), {
  'DESCRIPTOR' : _GEOTAGRESPONSE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuas.GeoTagResponse)
  })
_sym_db.RegisterMessage(GeoTagResponse)

UnGeoTagRequest = _reflection.GeneratedProtocolMessageType('UnGeoTagRequest', (_message.Message,), {
  'DESCRIPTOR' : _UNGEOTAGREQUEST,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuas.UnGeoTagRequest)
  })
_sym_db.RegisterMessage(UnGeoTagRequest)

UnGeoTagResponse = _reflection.GeneratedProtocolMessageType('UnGeoTagResponse', (_message.Message,), {
  'DESCRIPTOR' : _UNGEOTAGRESPONSE,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuas.UnGeoTagResponse)
  })
_sym_db.RegisterMessage(UnGeoTagResponse)

Telemetry = _reflection.GeneratedProtocolMessageType('Telemetry', (_message.Message,), {
  'DESCRIPTOR' : _TELEMETRY,
  '__module__' : 'uuaspb_pb2'
  # @@protoc_insertion_point(class_scope:uuas.Telemetry)
  })
_sym_db.RegisterMessage(Telemetry)


# @@protoc_insertion_point(module_scope)
