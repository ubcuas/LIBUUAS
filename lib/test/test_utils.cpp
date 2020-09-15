#include "test_utils.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

bool comparePrecision(long double x, long double y, int places) {
    const long double mod = pow(10, places);
    long xprime = static_cast<long>((x * mod) + 0.5);
    long yprime = static_cast<long>((y * mod) + 0.5);

    // std::cout << xprime << " - " << yprime << std::endl;
    return xprime == yprime;
}

bool comparePrecisionTrunc(long double x, long double y, int places) {
    const long double mod = pow(10, places);
    long xprime = static_cast<long>((x * mod));
    long yprime = static_cast<long>((y * mod));

    // std::cout << xprime << " - " << yprime << std::endl;
    return xprime == yprime;
}
