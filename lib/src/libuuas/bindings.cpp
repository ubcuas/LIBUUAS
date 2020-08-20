#include "libuuas/bindings.hpp"
#include "libuuas/geotag.hpp"
#include "libuuas/uuaspb.pb.h"
#include "libuuas/waypoint.hpp"
#include <iostream>

int32_t geotagImageRequest(const unsigned char* pbbuffer, uint32_t length, unsigned char* resppbbuffer, uint32_t resplength) {
    uuaspb::GeoTagRequest geotag_request;
    geotag_request.ParseFromArray(pbbuffer, length);

    uuaspb::GeoTagResponse geotag_response;
    try {
        geotag_response = libuuas::geotag::geotagImage(geotag_request);
    } catch (const std::exception &exc) {
        std::cout << exc.what() << std::endl;
        geotag_response.set_result(uuaspb::ResultStatus::ERR);
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
    } catch (const std::exception &exc) {
        std::cout << exc.what() << std::endl;
        geotag_response.set_result(uuaspb::ResultStatus::ERR);
    } catch (...) {
        geotag_response.set_result(uuaspb::ResultStatus::ERR);
    }

    if (resplength < geotag_response.ByteSizeLong()) {
        return -1;
    }

    geotag_response.SerializeToArray(resppbbuffer, resplength);
    return geotag_response.ByteSizeLong();
}

int32_t orderedRouteRequest(const unsigned char* pbbuffer, uint32_t length, unsigned char* resppbbuffer, uint32_t resplength) {
    uuaspb::OrderedRouteRequest ordered_route_request;
    bool parsed = ordered_route_request.ParseFromArray(pbbuffer, length);

    uuaspb::OrderedRouteResponse ordered_route_response;
    try {
        ordered_route_response = libuuas::waypointing::orderedRoute(ordered_route_request);
    } catch (const std::exception &exc) {
        std::cout << exc.what() << std::endl;
        ordered_route_response.set_result(uuaspb::ResultStatus::ERR);
    } catch (...) {
        ordered_route_response.set_result(uuaspb::ResultStatus::ERR);
    }

    if (resplength < ordered_route_response.ByteSizeLong()) {
        return -1;
    }

    ordered_route_response.SerializeToArray(resppbbuffer, resplength);
    return ordered_route_response.ByteSizeLong();
}
