#include "libuuas/bindings.hpp"
#include "libuuas/uuas.hpp"
#include "libuuas/uuaspb.pb.h"
#include <iostream>

int32_t geotagImageRequest(const unsigned char* pbbuffer, uint32_t length, unsigned char* resppbbuffer, uint32_t resplength) {
    uuas::GeoTagRequest geotag_request;
    geotag_request.ParseFromArray(pbbuffer, length);

    // Send to Luc's Function //

    uuas::GeoTagResponse geotag_response;
    geotag_response.set_result(uuas::ResultStatus::OK);

    if (resplength < geotag_response.ByteSizeLong()) {
        return -1;
    }

    geotag_response.SerializeToArray(resppbbuffer, resplength);
    return geotag_response.ByteSizeLong();
}

int32_t getImageGeotagRequest(const unsigned char* pbbuffer, uint32_t length, unsigned char* resppbbuffer, uint32_t resplength) {
    uuas::UnGeoTagRequest geotag_request;
    geotag_request.ParseFromArray(pbbuffer, length);

    // Send to Luc's Function //

    uuas::UnGeoTagResponse geotag_response;
    geotag_response.set_result(uuas::ResultStatus::OK);
    // geotag_response.set_telemetry(/* Luc's Result */);

    if (resplength < geotag_response.ByteSizeLong()) {
        return -1;
    }

    geotag_response.SerializeToArray(resppbbuffer, resplength);
    return geotag_response.ByteSizeLong();
}
