#define private public

#include "test_utils.hpp"
#include <catch2/catch.hpp>
#include <libuuas/geotag.hpp>

using namespace libuuas::geotag;

constexpr char testImageFilenameJPEG[] = "test/resources/images/image1.jpg";
constexpr char testImageFilenamePNG[] = "test/resources/images/image1.png";
constexpr char testImageFilenameWEBP[] = "test/resources/images/image1.webp";

TEST_CASE("Geotag should successfully tag telemetry data", "[geotag]") {
    uuaspb::GeoTagRequest request;
    request.set_filename(testImageFilenameJPEG);
    request.mutable_telemetry()->set_latitude_dege7(1);
    request.mutable_telemetry()->set_longitude_dege7(2);
    request.mutable_telemetry()->set_altitude_agl_m(3);
    request.mutable_telemetry()->set_altitude_msl_m(4);
    request.mutable_telemetry()->set_heading_deg(5);
    request.mutable_telemetry()->set_velocityx_m_s(6);
    request.mutable_telemetry()->set_velocityy_m_s(7);
    request.mutable_telemetry()->set_velocityz_m_s(8);
    request.mutable_telemetry()->set_roll_rad(9);
    request.mutable_telemetry()->set_pitch_rad(10);
    request.mutable_telemetry()->set_yaw_rad(11);
    request.mutable_telemetry()->set_rollspeed_rad_s(12);
    request.mutable_telemetry()->set_pitchspeed_rad_s(13);
    request.mutable_telemetry()->set_yawspeed_rad_s(14);
    request.mutable_telemetry()->set_timestamp_pixhawk_ms(15);
    request.mutable_telemetry()->set_timestamp_msg_ms(16);
    uuaspb::GeoTagResponse response = geotagImage(request);
    REQUIRE(response.result() == uuaspb::ResultStatus::OK);

    uuaspb::UnGeoTagRequest getRequest;
    getRequest.set_filename(testImageFilenameJPEG);
    uuaspb::UnGeoTagResponse getResponse = getImageGeotag(getRequest);
    REQUIRE(getResponse.result() == uuaspb::ResultStatus::OK);
    REQUIRE(getResponse.telemetry().latitude_dege7() == request.telemetry().latitude_dege7());
    REQUIRE(getResponse.telemetry().longitude_dege7() == request.telemetry().longitude_dege7());
    REQUIRE(getResponse.telemetry().altitude_agl_m() == request.telemetry().altitude_agl_m());
    REQUIRE(getResponse.telemetry().altitude_msl_m() == request.telemetry().altitude_msl_m());
    REQUIRE(getResponse.telemetry().heading_deg() == request.telemetry().heading_deg());
    REQUIRE(getResponse.telemetry().velocityx_m_s() == request.telemetry().velocityx_m_s());
    REQUIRE(getResponse.telemetry().velocityy_m_s() == request.telemetry().velocityy_m_s());
    REQUIRE(getResponse.telemetry().velocityz_m_s() == request.telemetry().velocityz_m_s());
    REQUIRE(getResponse.telemetry().roll_rad() == request.telemetry().roll_rad());
    REQUIRE(getResponse.telemetry().pitch_rad() == request.telemetry().pitch_rad());
    REQUIRE(getResponse.telemetry().yaw_rad() == request.telemetry().yaw_rad());
    REQUIRE(getResponse.telemetry().rollspeed_rad_s() == request.telemetry().rollspeed_rad_s());
    REQUIRE(getResponse.telemetry().pitchspeed_rad_s() == request.telemetry().pitchspeed_rad_s());
    REQUIRE(getResponse.telemetry().yawspeed_rad_s() == request.telemetry().yawspeed_rad_s());
    REQUIRE(getResponse.telemetry().timestamp_pixhawk_ms() == request.telemetry().timestamp_pixhawk_ms());
    REQUIRE(getResponse.telemetry().timestamp_msg_ms() == request.telemetry().timestamp_msg_ms());
}

TEST_CASE("Geotag should successfully geotag a JPEG image", "[geotag]") {
    uuaspb::GeoTagRequest request;
    request.set_filename(testImageFilenameJPEG);

    uuaspb::GeoTagResponse response = geotagImage(request);
    REQUIRE(response.result() == uuaspb::ResultStatus::OK);
}

TEST_CASE("Geotag should successfully geotag a PNG image", "[geotag]") {
    uuaspb::GeoTagRequest request;
    request.set_filename(testImageFilenamePNG);

    uuaspb::GeoTagResponse response = geotagImage(request);
    REQUIRE(response.result() == uuaspb::ResultStatus::OK);
}

TEST_CASE("Geotag should successfully geotag a WEBP image", "[geotag]") {
    uuaspb::GeoTagRequest request;
    request.set_filename(testImageFilenameWEBP);

    uuaspb::GeoTagResponse response = geotagImage(request);
    REQUIRE(response.result() == uuaspb::ResultStatus::OK);
}
