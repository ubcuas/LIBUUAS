#include "libuuas/bindings.hpp"
#include "libuuas/geotag.hpp"
#include "libuuas/uuaspb.pb.h"
#include <iostream>

int32_t geotagImageRequest(const unsigned char* pbbuffer, uint32_t length, unsigned char* resppbbuffer, uint32_t resplength) {
    uuaspb::GeoTagRequest geotag_request;
    geotag_request.ParseFromArray(pbbuffer, length);

    uuaspb::GeoTagResponse geotag_response;
    try {
        geotag_response = libuuas::geotag::geotagImage(geotag_request);
    } catch (...) {
        geotag_response.set_result(uuaspb::ResultStatus::ERR);
    }

    if (resplength < geotag_response.ByteSizeLong()) {
        return -1;
    }

    geotag_response.SerializeToArray(resppbbuffer, resplength);
    return geotag_response.ByteSizeLong();
}

int32_t getImageGeotagRequest(const unsigned char* pbbuffer, uint32_t length, unsigned char* resppbbuffer, uint32_t resplength) {
    uuaspb::UnGeoTagRequest geotag_request;
    bool parsed = geotag_request.ParseFromArray(pbbuffer, length);

    uuaspb::UnGeoTagResponse geotag_response;
    try {
        geotag_response = libuuas::geotag::getImageGeotag(geotag_request);
    } catch (...) {
        geotag_response.set_result(uuaspb::ResultStatus::ERR);
    }

    if (resplength < geotag_response.ByteSizeLong()) {
        return -1;
    }

    geotag_response.SerializeToArray(resppbbuffer, resplength);
    return geotag_response.ByteSizeLong();
}
