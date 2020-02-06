#include "img_tools.hh"


FIBITMAP *load_img(const char *src) {
    FIBITMAP *bitmap = FreeImage_Load(FIF_PNG, src, PNG_DEFAULT);
    return bitmap;
}

void save_img(FIBITMAP *bitmap, const char *dst) {
    FreeImage_Save(FIF_PNG, bitmap, dst, 0);
}