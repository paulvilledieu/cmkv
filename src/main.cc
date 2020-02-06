#include "img_tools.hh"

using namespace std;

int main(int argc, char *argv[]) {
    FreeImage_Initialise();

    FIBITMAP *bitmap = load_img("img/parrots.png");
    save_img(bitmap, "img/cpy.png");

    FreeImage_DeInitialise();
}
