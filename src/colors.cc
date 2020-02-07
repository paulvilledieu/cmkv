#include "../include/colors.hh"
#include <cmath>

float distance(const RGBQUAD &a, const RGBQUAD &b) {
    return sqrt(pow(static_cast<float>(a.rgbRed) - static_cast<float>(b.rgbRed), 2)
                + pow(static_cast<float>(a.rgbGreen) - static_cast<float>(b.rgbGreen), 2)
                + pow(static_cast<float>(a.rgbBlue) - static_cast<float>(b.rgbBlue), 2));
}
