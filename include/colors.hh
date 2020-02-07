#ifndef CMKV_COLORS_HH
#define CMKV_COLORS_HH

#include "img_tools.hh"


typedef struct lab {
    double l;
    double a;
    double b;
} lab;

lab rgb2lab(RGBQUAD rgb);

float distance(const RGBQUAD &a, const RGBQUAD &b);

float distance(const lab &a, const lab &b);

#endif //CMKV_COLORS_HH
