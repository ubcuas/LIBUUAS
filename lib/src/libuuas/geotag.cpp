#include "libuuas/geotag.hpp"
#include <exiv2/exiv2.hpp>
#include <iostream>
#include <sstream>
#include <string>

namespace libuuas {
namespace geotag {

    std::string dtos(double value) {
        return std::to_string(value);
    }

    std::string u64tos(uint64_t value) {
        return std::to_string(value);
    }

    uuaspb::GeoTagResponse geotagImage(uuaspb::GeoTagRequest geotagRequest) {
        Exiv2::XmpProperties::registerNs("UAS/", "UAS");

        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(geotagRequest.filename());
        image->readMetadata();
        Exiv2::XmpData& XMPData = image->xmpData();

        XMPData["Xmp.UAS.latitude_dege7"] = dtos(geotagRequest.telemetry().latitude_dege7());
        XMPData["Xmp.UAS.longitude_dege7"] = dtos(geotagRequest.telemetry().longitude_dege7());
        XMPData["Xmp.UAS.altitude_agl_m"] = dtos(geotagRequest.telemetry().altitude_agl_m());
        XMPData["Xmp.UAS.altitude_msl_m"] = dtos(geotagRequest.telemetry().altitude_msl_m());
        XMPData["Xmp.UAS.heading_deg"] = dtos(geotagRequest.telemetry().heading_deg());
        XMPData["Xmp.UAS.velocityx_m_s"] = dtos(geotagRequest.telemetry().velocityx_m_s());
        XMPData["Xmp.UAS.velocityy_m_s"] = dtos(geotagRequest.telemetry().velocityy_m_s());
        XMPData["Xmp.UAS.velocityz_m_s"] = dtos(geotagRequest.telemetry().velocityz_m_s());
        XMPData["Xmp.UAS.roll_rad"] = dtos(geotagRequest.telemetry().roll_rad());
        XMPData["Xmp.UAS.pitch_rad"] = dtos(geotagRequest.telemetry().pitch_rad());
        XMPData["Xmp.UAS.yaw_rad"] = dtos(geotagRequest.telemetry().yaw_rad());
        XMPData["Xmp.UAS.rollspeed_rad_s"] = dtos(geotagRequest.telemetry().rollspeed_rad_s());
        XMPData["Xmp.UAS.pitchspeed_rad_s"] = dtos(geotagRequest.telemetry().pitchspeed_rad_s());
        XMPData["Xmp.UAS.yawspeed_rad_s"] = dtos(geotagRequest.telemetry().yawspeed_rad_s());
        XMPData["Xmp.UAS.timestamp_pixhawk_ms"] = u64tos(geotagRequest.telemetry().timestamp_pixhawk_ms());
        XMPData["Xmp.UAS.timestamp_msg_ms"] = u64tos(geotagRequest.telemetry().timestamp_msg_ms());

        image->setXmpData(XMPData);
        image->writeMetadata();
        image.release();

        std::cout << "Wrote XMP data to " << geotagRequest.filename() << std::endl;

        uuaspb::GeoTagResponse geotag_response;
        geotag_response.set_result(uuaspb::ResultStatus::OK);
        return geotag_response;
    }

    uuaspb::UnGeoTagResponse getImageGeotag(uuaspb::UnGeoTagRequest unGeotagRequest) {
        Exiv2::XmpProperties::registerNs("UAS/", "UAS");

        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(unGeotagRequest.filename());
        image->readMetadata();
        Exiv2::XmpData& XMPData = image->xmpData();

        std::cout << "Reading XMP data from " << unGeotagRequest.filename() << std::endl;
        uuaspb::UnGeoTagResponse unGeotag_response;

        const Exiv2::Value& latitude_dege7 = XMPData["Xmp.UAS.latitude_dege7"].value();
        unGeotag_response.mutable_telemetry()->set_latitude_dege7(std::stod(latitude_dege7.toString()));
        const Exiv2::Value& longitude_dege7 = XMPData["Xmp.UAS.longitude_dege7"].value();
        unGeotag_response.mutable_telemetry()->set_longitude_dege7(std::stod(longitude_dege7.toString()));
        const Exiv2::Value& altitude_agl_m = XMPData["Xmp.UAS.altitude_agl_m"].value();
        unGeotag_response.mutable_telemetry()->set_altitude_agl_m(std::stod(altitude_agl_m.toString()));
        const Exiv2::Value& altitude_msl_m = XMPData["Xmp.UAS.altitude_msl_m"].value();
        unGeotag_response.mutable_telemetry()->set_altitude_msl_m(std::stod(altitude_msl_m.toString()));
        const Exiv2::Value& heading_deg = XMPData["Xmp.UAS.heading_deg"].value();
        unGeotag_response.mutable_telemetry()->set_heading_deg(std::stod(heading_deg.toString()));
        const Exiv2::Value& velocityx_m_s = XMPData["Xmp.UAS.velocityx_m_s"].value();
        unGeotag_response.mutable_telemetry()->set_velocityx_m_s(std::stod(velocityx_m_s.toString()));
        const Exiv2::Value& velocityy_m_s = XMPData["Xmp.UAS.velocityy_m_s"].value();
        unGeotag_response.mutable_telemetry()->set_velocityy_m_s(std::stod(velocityy_m_s.toString()));
        const Exiv2::Value& velocityz_m_s = XMPData["Xmp.UAS.velocityz_m_s"].value();
        unGeotag_response.mutable_telemetry()->set_velocityz_m_s(std::stod(velocityz_m_s.toString()));
        const Exiv2::Value& roll_rad = XMPData["Xmp.UAS.roll_rad"].value();
        unGeotag_response.mutable_telemetry()->set_roll_rad(std::stod(roll_rad.toString()));
        const Exiv2::Value& pitch_rad = XMPData["Xmp.UAS.pitch_rad"].value();
        unGeotag_response.mutable_telemetry()->set_pitch_rad(std::stod(pitch_rad.toString()));
        const Exiv2::Value& yaw_rad = XMPData["Xmp.UAS.yaw_rad"].value();
        unGeotag_response.mutable_telemetry()->set_yaw_rad(std::stod(yaw_rad.toString()));
        const Exiv2::Value& rollspeed_rad_s = XMPData["Xmp.UAS.rollspeed_rad_s"].value();
        unGeotag_response.mutable_telemetry()->set_rollspeed_rad_s(std::stod(rollspeed_rad_s.toString()));
        const Exiv2::Value& pitchspeed_rad_s = XMPData["Xmp.UAS.pitchspeed_rad_s"].value();
        unGeotag_response.mutable_telemetry()->set_pitchspeed_rad_s(std::stod(pitchspeed_rad_s.toString()));
        const Exiv2::Value& yawspeed_rad_s = XMPData["Xmp.UAS.yawspeed_rad_s"].value();
        unGeotag_response.mutable_telemetry()->set_yawspeed_rad_s(std::stod(yawspeed_rad_s.toString()));
        const Exiv2::Value& timestamp_pixhawk_ms = XMPData["Xmp.UAS.timestamp_pixhawk_ms"].value();
        unGeotag_response.mutable_telemetry()->set_timestamp_pixhawk_ms(std::stoi(timestamp_pixhawk_ms.toString()));
        const Exiv2::Value& timestamp_msg_ms = XMPData["Xmp.UAS.timestamp_msg_ms"].value();
        unGeotag_response.mutable_telemetry()->set_timestamp_msg_ms(std::stoi(timestamp_msg_ms.toString()));

        image->writeMetadata(); // Apparently not writing the metadata back means Exiv2 will clear it from the image
        image.release();

        unGeotag_response.set_result(uuaspb::ResultStatus::OK);
        return unGeotag_response;
    }

} // geotag
} // libuuas
