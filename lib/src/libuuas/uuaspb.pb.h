// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: uuaspb.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_uuaspb_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_uuaspb_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_uuaspb_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_uuaspb_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_uuaspb_2eproto;
namespace uuas {
class GeoTagRequest;
class GeoTagRequestDefaultTypeInternal;
extern GeoTagRequestDefaultTypeInternal _GeoTagRequest_default_instance_;
class Telemetry;
class TelemetryDefaultTypeInternal;
extern TelemetryDefaultTypeInternal _Telemetry_default_instance_;
}  // namespace uuas
PROTOBUF_NAMESPACE_OPEN
template<> ::uuas::GeoTagRequest* Arena::CreateMaybeMessage<::uuas::GeoTagRequest>(Arena*);
template<> ::uuas::Telemetry* Arena::CreateMaybeMessage<::uuas::Telemetry>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace uuas {

// ===================================================================

class GeoTagRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:uuas.GeoTagRequest) */ {
 public:
  inline GeoTagRequest() : GeoTagRequest(nullptr) {};
  virtual ~GeoTagRequest();

  GeoTagRequest(const GeoTagRequest& from);
  GeoTagRequest(GeoTagRequest&& from) noexcept
    : GeoTagRequest() {
    *this = ::std::move(from);
  }

  inline GeoTagRequest& operator=(const GeoTagRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline GeoTagRequest& operator=(GeoTagRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const GeoTagRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GeoTagRequest* internal_default_instance() {
    return reinterpret_cast<const GeoTagRequest*>(
               &_GeoTagRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GeoTagRequest& a, GeoTagRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(GeoTagRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GeoTagRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GeoTagRequest* New() const final {
    return CreateMaybeMessage<GeoTagRequest>(nullptr);
  }

  GeoTagRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GeoTagRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GeoTagRequest& from);
  void MergeFrom(const GeoTagRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GeoTagRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "uuas.GeoTagRequest";
  }
  protected:
  explicit GeoTagRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_uuaspb_2eproto);
    return ::descriptor_table_uuaspb_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilenameFieldNumber = 1,
    kTelemetryFieldNumber = 2,
  };
  // string filename = 1;
  void clear_filename();
  const std::string& filename() const;
  void set_filename(const std::string& value);
  void set_filename(std::string&& value);
  void set_filename(const char* value);
  void set_filename(const char* value, size_t size);
  std::string* mutable_filename();
  std::string* release_filename();
  void set_allocated_filename(std::string* filename);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_filename();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_filename(
      std::string* filename);
  private:
  const std::string& _internal_filename() const;
  void _internal_set_filename(const std::string& value);
  std::string* _internal_mutable_filename();
  public:

  // .uuas.Telemetry telemetry = 2;
  bool has_telemetry() const;
  private:
  bool _internal_has_telemetry() const;
  public:
  void clear_telemetry();
  const ::uuas::Telemetry& telemetry() const;
  ::uuas::Telemetry* release_telemetry();
  ::uuas::Telemetry* mutable_telemetry();
  void set_allocated_telemetry(::uuas::Telemetry* telemetry);
  private:
  const ::uuas::Telemetry& _internal_telemetry() const;
  ::uuas::Telemetry* _internal_mutable_telemetry();
  public:
  void unsafe_arena_set_allocated_telemetry(
      ::uuas::Telemetry* telemetry);
  ::uuas::Telemetry* unsafe_arena_release_telemetry();

  // @@protoc_insertion_point(class_scope:uuas.GeoTagRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr filename_;
  ::uuas::Telemetry* telemetry_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_uuaspb_2eproto;
};
// -------------------------------------------------------------------

class Telemetry PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:uuas.Telemetry) */ {
 public:
  inline Telemetry() : Telemetry(nullptr) {};
  virtual ~Telemetry();

  Telemetry(const Telemetry& from);
  Telemetry(Telemetry&& from) noexcept
    : Telemetry() {
    *this = ::std::move(from);
  }

  inline Telemetry& operator=(const Telemetry& from) {
    CopyFrom(from);
    return *this;
  }
  inline Telemetry& operator=(Telemetry&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Telemetry& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Telemetry* internal_default_instance() {
    return reinterpret_cast<const Telemetry*>(
               &_Telemetry_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Telemetry& a, Telemetry& b) {
    a.Swap(&b);
  }
  inline void Swap(Telemetry* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Telemetry* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Telemetry* New() const final {
    return CreateMaybeMessage<Telemetry>(nullptr);
  }

  Telemetry* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Telemetry>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Telemetry& from);
  void MergeFrom(const Telemetry& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Telemetry* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "uuas.Telemetry";
  }
  protected:
  explicit Telemetry(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_uuaspb_2eproto);
    return ::descriptor_table_uuaspb_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLatitudeFieldNumber = 1,
    kLongitudeFieldNumber = 2,
    kAltitudeAglMetersFieldNumber = 3,
    kAltitudeMslMetersFieldNumber = 4,
    kVelocityXCmSFieldNumber = 6,
    kVelocityYCmSFieldNumber = 7,
    kVelocityZCmSFieldNumber = 8,
    kRollRadFieldNumber = 9,
    kPitchRadFieldNumber = 10,
    kYawRadFieldNumber = 11,
    kRollspeedRadSFieldNumber = 12,
    kPitchspeedRadSFieldNumber = 13,
    kYawspeedRadSFieldNumber = 14,
    kTimestampTelemMsFieldNumber = 15,
    kTimestampMsgMsFieldNumber = 16,
    kHeadingDegreesFieldNumber = 5,
  };
  // sint64 latitude = 1;
  void clear_latitude();
  ::PROTOBUF_NAMESPACE_ID::int64 latitude() const;
  void set_latitude(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_latitude() const;
  void _internal_set_latitude(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // sint64 longitude = 2;
  void clear_longitude();
  ::PROTOBUF_NAMESPACE_ID::int64 longitude() const;
  void set_longitude(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_longitude() const;
  void _internal_set_longitude(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // uint32 altitude_agl_meters = 3;
  void clear_altitude_agl_meters();
  ::PROTOBUF_NAMESPACE_ID::uint32 altitude_agl_meters() const;
  void set_altitude_agl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_altitude_agl_meters() const;
  void _internal_set_altitude_agl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 altitude_msl_meters = 4;
  void clear_altitude_msl_meters();
  ::PROTOBUF_NAMESPACE_ID::uint32 altitude_msl_meters() const;
  void set_altitude_msl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_altitude_msl_meters() const;
  void _internal_set_altitude_msl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // double velocity_x_cm_s = 6;
  void clear_velocity_x_cm_s();
  double velocity_x_cm_s() const;
  void set_velocity_x_cm_s(double value);
  private:
  double _internal_velocity_x_cm_s() const;
  void _internal_set_velocity_x_cm_s(double value);
  public:

  // double velocity_y_cm_s = 7;
  void clear_velocity_y_cm_s();
  double velocity_y_cm_s() const;
  void set_velocity_y_cm_s(double value);
  private:
  double _internal_velocity_y_cm_s() const;
  void _internal_set_velocity_y_cm_s(double value);
  public:

  // double velocity_z_cm_s = 8;
  void clear_velocity_z_cm_s();
  double velocity_z_cm_s() const;
  void set_velocity_z_cm_s(double value);
  private:
  double _internal_velocity_z_cm_s() const;
  void _internal_set_velocity_z_cm_s(double value);
  public:

  // double roll_rad = 9;
  void clear_roll_rad();
  double roll_rad() const;
  void set_roll_rad(double value);
  private:
  double _internal_roll_rad() const;
  void _internal_set_roll_rad(double value);
  public:

  // double pitch_rad = 10;
  void clear_pitch_rad();
  double pitch_rad() const;
  void set_pitch_rad(double value);
  private:
  double _internal_pitch_rad() const;
  void _internal_set_pitch_rad(double value);
  public:

  // double yaw_rad = 11;
  void clear_yaw_rad();
  double yaw_rad() const;
  void set_yaw_rad(double value);
  private:
  double _internal_yaw_rad() const;
  void _internal_set_yaw_rad(double value);
  public:

  // double rollspeed_rad_s = 12;
  void clear_rollspeed_rad_s();
  double rollspeed_rad_s() const;
  void set_rollspeed_rad_s(double value);
  private:
  double _internal_rollspeed_rad_s() const;
  void _internal_set_rollspeed_rad_s(double value);
  public:

  // double pitchspeed_rad_s = 13;
  void clear_pitchspeed_rad_s();
  double pitchspeed_rad_s() const;
  void set_pitchspeed_rad_s(double value);
  private:
  double _internal_pitchspeed_rad_s() const;
  void _internal_set_pitchspeed_rad_s(double value);
  public:

  // double yawspeed_rad_s = 14;
  void clear_yawspeed_rad_s();
  double yawspeed_rad_s() const;
  void set_yawspeed_rad_s(double value);
  private:
  double _internal_yawspeed_rad_s() const;
  void _internal_set_yawspeed_rad_s(double value);
  public:

  // uint64 timestamp_telem_ms = 15;
  void clear_timestamp_telem_ms();
  ::PROTOBUF_NAMESPACE_ID::uint64 timestamp_telem_ms() const;
  void set_timestamp_telem_ms(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_timestamp_telem_ms() const;
  void _internal_set_timestamp_telem_ms(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // uint64 timestamp_msg_ms = 16;
  void clear_timestamp_msg_ms();
  ::PROTOBUF_NAMESPACE_ID::uint64 timestamp_msg_ms() const;
  void set_timestamp_msg_ms(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_timestamp_msg_ms() const;
  void _internal_set_timestamp_msg_ms(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // uint32 heading_degrees = 5;
  void clear_heading_degrees();
  ::PROTOBUF_NAMESPACE_ID::uint32 heading_degrees() const;
  void set_heading_degrees(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_heading_degrees() const;
  void _internal_set_heading_degrees(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:uuas.Telemetry)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int64 latitude_;
  ::PROTOBUF_NAMESPACE_ID::int64 longitude_;
  ::PROTOBUF_NAMESPACE_ID::uint32 altitude_agl_meters_;
  ::PROTOBUF_NAMESPACE_ID::uint32 altitude_msl_meters_;
  double velocity_x_cm_s_;
  double velocity_y_cm_s_;
  double velocity_z_cm_s_;
  double roll_rad_;
  double pitch_rad_;
  double yaw_rad_;
  double rollspeed_rad_s_;
  double pitchspeed_rad_s_;
  double yawspeed_rad_s_;
  ::PROTOBUF_NAMESPACE_ID::uint64 timestamp_telem_ms_;
  ::PROTOBUF_NAMESPACE_ID::uint64 timestamp_msg_ms_;
  ::PROTOBUF_NAMESPACE_ID::uint32 heading_degrees_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_uuaspb_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GeoTagRequest

// string filename = 1;
inline void GeoTagRequest::clear_filename() {
  filename_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& GeoTagRequest::filename() const {
  // @@protoc_insertion_point(field_get:uuas.GeoTagRequest.filename)
  return _internal_filename();
}
inline void GeoTagRequest::set_filename(const std::string& value) {
  _internal_set_filename(value);
  // @@protoc_insertion_point(field_set:uuas.GeoTagRequest.filename)
}
inline std::string* GeoTagRequest::mutable_filename() {
  // @@protoc_insertion_point(field_mutable:uuas.GeoTagRequest.filename)
  return _internal_mutable_filename();
}
inline const std::string& GeoTagRequest::_internal_filename() const {
  return filename_.Get();
}
inline void GeoTagRequest::_internal_set_filename(const std::string& value) {
  
  filename_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void GeoTagRequest::set_filename(std::string&& value) {
  
  filename_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:uuas.GeoTagRequest.filename)
}
inline void GeoTagRequest::set_filename(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  filename_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:uuas.GeoTagRequest.filename)
}
inline void GeoTagRequest::set_filename(const char* value,
    size_t size) {
  
  filename_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:uuas.GeoTagRequest.filename)
}
inline std::string* GeoTagRequest::_internal_mutable_filename() {
  
  return filename_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* GeoTagRequest::release_filename() {
  // @@protoc_insertion_point(field_release:uuas.GeoTagRequest.filename)
  return filename_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GeoTagRequest::set_allocated_filename(std::string* filename) {
  if (filename != nullptr) {
    
  } else {
    
  }
  filename_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), filename,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:uuas.GeoTagRequest.filename)
}
inline std::string* GeoTagRequest::unsafe_arena_release_filename() {
  // @@protoc_insertion_point(field_unsafe_arena_release:uuas.GeoTagRequest.filename)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return filename_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void GeoTagRequest::unsafe_arena_set_allocated_filename(
    std::string* filename) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (filename != nullptr) {
    
  } else {
    
  }
  filename_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      filename, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:uuas.GeoTagRequest.filename)
}

// .uuas.Telemetry telemetry = 2;
inline bool GeoTagRequest::_internal_has_telemetry() const {
  return this != internal_default_instance() && telemetry_ != nullptr;
}
inline bool GeoTagRequest::has_telemetry() const {
  return _internal_has_telemetry();
}
inline void GeoTagRequest::clear_telemetry() {
  if (GetArena() == nullptr && telemetry_ != nullptr) {
    delete telemetry_;
  }
  telemetry_ = nullptr;
}
inline const ::uuas::Telemetry& GeoTagRequest::_internal_telemetry() const {
  const ::uuas::Telemetry* p = telemetry_;
  return p != nullptr ? *p : *reinterpret_cast<const ::uuas::Telemetry*>(
      &::uuas::_Telemetry_default_instance_);
}
inline const ::uuas::Telemetry& GeoTagRequest::telemetry() const {
  // @@protoc_insertion_point(field_get:uuas.GeoTagRequest.telemetry)
  return _internal_telemetry();
}
inline void GeoTagRequest::unsafe_arena_set_allocated_telemetry(
    ::uuas::Telemetry* telemetry) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(telemetry_);
  }
  telemetry_ = telemetry;
  if (telemetry) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:uuas.GeoTagRequest.telemetry)
}
inline ::uuas::Telemetry* GeoTagRequest::release_telemetry() {
  auto temp = unsafe_arena_release_telemetry();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::uuas::Telemetry* GeoTagRequest::unsafe_arena_release_telemetry() {
  // @@protoc_insertion_point(field_release:uuas.GeoTagRequest.telemetry)
  
  ::uuas::Telemetry* temp = telemetry_;
  telemetry_ = nullptr;
  return temp;
}
inline ::uuas::Telemetry* GeoTagRequest::_internal_mutable_telemetry() {
  
  if (telemetry_ == nullptr) {
    auto* p = CreateMaybeMessage<::uuas::Telemetry>(GetArena());
    telemetry_ = p;
  }
  return telemetry_;
}
inline ::uuas::Telemetry* GeoTagRequest::mutable_telemetry() {
  // @@protoc_insertion_point(field_mutable:uuas.GeoTagRequest.telemetry)
  return _internal_mutable_telemetry();
}
inline void GeoTagRequest::set_allocated_telemetry(::uuas::Telemetry* telemetry) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete telemetry_;
  }
  if (telemetry) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(telemetry);
    if (message_arena != submessage_arena) {
      telemetry = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, telemetry, submessage_arena);
    }
    
  } else {
    
  }
  telemetry_ = telemetry;
  // @@protoc_insertion_point(field_set_allocated:uuas.GeoTagRequest.telemetry)
}

// -------------------------------------------------------------------

// Telemetry

// sint64 latitude = 1;
inline void Telemetry::clear_latitude() {
  latitude_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Telemetry::_internal_latitude() const {
  return latitude_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Telemetry::latitude() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.latitude)
  return _internal_latitude();
}
inline void Telemetry::_internal_set_latitude(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  latitude_ = value;
}
inline void Telemetry::set_latitude(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_latitude(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.latitude)
}

// sint64 longitude = 2;
inline void Telemetry::clear_longitude() {
  longitude_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Telemetry::_internal_longitude() const {
  return longitude_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 Telemetry::longitude() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.longitude)
  return _internal_longitude();
}
inline void Telemetry::_internal_set_longitude(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  longitude_ = value;
}
inline void Telemetry::set_longitude(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_longitude(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.longitude)
}

// uint32 altitude_agl_meters = 3;
inline void Telemetry::clear_altitude_agl_meters() {
  altitude_agl_meters_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Telemetry::_internal_altitude_agl_meters() const {
  return altitude_agl_meters_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Telemetry::altitude_agl_meters() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.altitude_agl_meters)
  return _internal_altitude_agl_meters();
}
inline void Telemetry::_internal_set_altitude_agl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  altitude_agl_meters_ = value;
}
inline void Telemetry::set_altitude_agl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_altitude_agl_meters(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.altitude_agl_meters)
}

// uint32 altitude_msl_meters = 4;
inline void Telemetry::clear_altitude_msl_meters() {
  altitude_msl_meters_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Telemetry::_internal_altitude_msl_meters() const {
  return altitude_msl_meters_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Telemetry::altitude_msl_meters() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.altitude_msl_meters)
  return _internal_altitude_msl_meters();
}
inline void Telemetry::_internal_set_altitude_msl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  altitude_msl_meters_ = value;
}
inline void Telemetry::set_altitude_msl_meters(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_altitude_msl_meters(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.altitude_msl_meters)
}

// uint32 heading_degrees = 5;
inline void Telemetry::clear_heading_degrees() {
  heading_degrees_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Telemetry::_internal_heading_degrees() const {
  return heading_degrees_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Telemetry::heading_degrees() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.heading_degrees)
  return _internal_heading_degrees();
}
inline void Telemetry::_internal_set_heading_degrees(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  heading_degrees_ = value;
}
inline void Telemetry::set_heading_degrees(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_heading_degrees(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.heading_degrees)
}

// double velocity_x_cm_s = 6;
inline void Telemetry::clear_velocity_x_cm_s() {
  velocity_x_cm_s_ = 0;
}
inline double Telemetry::_internal_velocity_x_cm_s() const {
  return velocity_x_cm_s_;
}
inline double Telemetry::velocity_x_cm_s() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.velocity_x_cm_s)
  return _internal_velocity_x_cm_s();
}
inline void Telemetry::_internal_set_velocity_x_cm_s(double value) {
  
  velocity_x_cm_s_ = value;
}
inline void Telemetry::set_velocity_x_cm_s(double value) {
  _internal_set_velocity_x_cm_s(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.velocity_x_cm_s)
}

// double velocity_y_cm_s = 7;
inline void Telemetry::clear_velocity_y_cm_s() {
  velocity_y_cm_s_ = 0;
}
inline double Telemetry::_internal_velocity_y_cm_s() const {
  return velocity_y_cm_s_;
}
inline double Telemetry::velocity_y_cm_s() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.velocity_y_cm_s)
  return _internal_velocity_y_cm_s();
}
inline void Telemetry::_internal_set_velocity_y_cm_s(double value) {
  
  velocity_y_cm_s_ = value;
}
inline void Telemetry::set_velocity_y_cm_s(double value) {
  _internal_set_velocity_y_cm_s(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.velocity_y_cm_s)
}

// double velocity_z_cm_s = 8;
inline void Telemetry::clear_velocity_z_cm_s() {
  velocity_z_cm_s_ = 0;
}
inline double Telemetry::_internal_velocity_z_cm_s() const {
  return velocity_z_cm_s_;
}
inline double Telemetry::velocity_z_cm_s() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.velocity_z_cm_s)
  return _internal_velocity_z_cm_s();
}
inline void Telemetry::_internal_set_velocity_z_cm_s(double value) {
  
  velocity_z_cm_s_ = value;
}
inline void Telemetry::set_velocity_z_cm_s(double value) {
  _internal_set_velocity_z_cm_s(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.velocity_z_cm_s)
}

// double roll_rad = 9;
inline void Telemetry::clear_roll_rad() {
  roll_rad_ = 0;
}
inline double Telemetry::_internal_roll_rad() const {
  return roll_rad_;
}
inline double Telemetry::roll_rad() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.roll_rad)
  return _internal_roll_rad();
}
inline void Telemetry::_internal_set_roll_rad(double value) {
  
  roll_rad_ = value;
}
inline void Telemetry::set_roll_rad(double value) {
  _internal_set_roll_rad(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.roll_rad)
}

// double pitch_rad = 10;
inline void Telemetry::clear_pitch_rad() {
  pitch_rad_ = 0;
}
inline double Telemetry::_internal_pitch_rad() const {
  return pitch_rad_;
}
inline double Telemetry::pitch_rad() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.pitch_rad)
  return _internal_pitch_rad();
}
inline void Telemetry::_internal_set_pitch_rad(double value) {
  
  pitch_rad_ = value;
}
inline void Telemetry::set_pitch_rad(double value) {
  _internal_set_pitch_rad(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.pitch_rad)
}

// double yaw_rad = 11;
inline void Telemetry::clear_yaw_rad() {
  yaw_rad_ = 0;
}
inline double Telemetry::_internal_yaw_rad() const {
  return yaw_rad_;
}
inline double Telemetry::yaw_rad() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.yaw_rad)
  return _internal_yaw_rad();
}
inline void Telemetry::_internal_set_yaw_rad(double value) {
  
  yaw_rad_ = value;
}
inline void Telemetry::set_yaw_rad(double value) {
  _internal_set_yaw_rad(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.yaw_rad)
}

// double rollspeed_rad_s = 12;
inline void Telemetry::clear_rollspeed_rad_s() {
  rollspeed_rad_s_ = 0;
}
inline double Telemetry::_internal_rollspeed_rad_s() const {
  return rollspeed_rad_s_;
}
inline double Telemetry::rollspeed_rad_s() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.rollspeed_rad_s)
  return _internal_rollspeed_rad_s();
}
inline void Telemetry::_internal_set_rollspeed_rad_s(double value) {
  
  rollspeed_rad_s_ = value;
}
inline void Telemetry::set_rollspeed_rad_s(double value) {
  _internal_set_rollspeed_rad_s(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.rollspeed_rad_s)
}

// double pitchspeed_rad_s = 13;
inline void Telemetry::clear_pitchspeed_rad_s() {
  pitchspeed_rad_s_ = 0;
}
inline double Telemetry::_internal_pitchspeed_rad_s() const {
  return pitchspeed_rad_s_;
}
inline double Telemetry::pitchspeed_rad_s() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.pitchspeed_rad_s)
  return _internal_pitchspeed_rad_s();
}
inline void Telemetry::_internal_set_pitchspeed_rad_s(double value) {
  
  pitchspeed_rad_s_ = value;
}
inline void Telemetry::set_pitchspeed_rad_s(double value) {
  _internal_set_pitchspeed_rad_s(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.pitchspeed_rad_s)
}

// double yawspeed_rad_s = 14;
inline void Telemetry::clear_yawspeed_rad_s() {
  yawspeed_rad_s_ = 0;
}
inline double Telemetry::_internal_yawspeed_rad_s() const {
  return yawspeed_rad_s_;
}
inline double Telemetry::yawspeed_rad_s() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.yawspeed_rad_s)
  return _internal_yawspeed_rad_s();
}
inline void Telemetry::_internal_set_yawspeed_rad_s(double value) {
  
  yawspeed_rad_s_ = value;
}
inline void Telemetry::set_yawspeed_rad_s(double value) {
  _internal_set_yawspeed_rad_s(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.yawspeed_rad_s)
}

// uint64 timestamp_telem_ms = 15;
inline void Telemetry::clear_timestamp_telem_ms() {
  timestamp_telem_ms_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Telemetry::_internal_timestamp_telem_ms() const {
  return timestamp_telem_ms_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Telemetry::timestamp_telem_ms() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.timestamp_telem_ms)
  return _internal_timestamp_telem_ms();
}
inline void Telemetry::_internal_set_timestamp_telem_ms(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  timestamp_telem_ms_ = value;
}
inline void Telemetry::set_timestamp_telem_ms(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_timestamp_telem_ms(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.timestamp_telem_ms)
}

// uint64 timestamp_msg_ms = 16;
inline void Telemetry::clear_timestamp_msg_ms() {
  timestamp_msg_ms_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Telemetry::_internal_timestamp_msg_ms() const {
  return timestamp_msg_ms_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Telemetry::timestamp_msg_ms() const {
  // @@protoc_insertion_point(field_get:uuas.Telemetry.timestamp_msg_ms)
  return _internal_timestamp_msg_ms();
}
inline void Telemetry::_internal_set_timestamp_msg_ms(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  timestamp_msg_ms_ = value;
}
inline void Telemetry::set_timestamp_msg_ms(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_timestamp_msg_ms(value);
  // @@protoc_insertion_point(field_set:uuas.Telemetry.timestamp_msg_ms)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace uuas

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_uuaspb_2eproto
