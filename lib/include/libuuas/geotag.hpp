#pragma once

#include "libuuas/uuaspb.pb.h"

namespace libuuas {
namespace geotag {

    uuaspb::GeoTagResponse geotagImage(uuaspb::GeoTagRequest geotagRequest);
    uuaspb::UnGeoTagResponse getImageGeotag(uuaspb::UnGeoTagRequest unGeotagRequest);

} // geotag
} // libuuas
