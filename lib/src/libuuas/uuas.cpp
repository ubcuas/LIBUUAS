#include "libuuas/uuas.hpp"
#include "uuaspb.pb.h"
#include <iostream>

int32_t geotagImageRequest(const unsigned char* pbbuffer, int32_t length) {
    return (length > 0) ? 0 : 1;
}

int32_t double_nums(int32_t a, int32_t b) {
    return a + b;
}
