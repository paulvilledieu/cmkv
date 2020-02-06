#pragma once
#include <FreeImage.h>


FIBITMAP *load_img(const char *src);

void save_img(FIBITMAP *bitmap, const char *dst);
