
#include <vector>
#include <cfloat>
#include <cmath>
#include <iostream>
#include "../include/img_tools.hh"
#include "../include/colors.hh"

using namespace std;

std::vector<RGBQUAD> colors = {
        { 0, 0, 0},         // BLACK
        { 255, 0, 0},       // BLUE
        { 0, 255, 0},       // GREEN
        { 0, 0, 255},       // RED
        { 255, 255, 0},     // CYAN
        { 255, 0, 255},     // MAGENTA
        { 0, 255, 255},     // YELLOW
        { 255, 255, 255},   // WHITE
};

void colorReduction(FIBITMAP *bitmap) {
    RGBQUAD c;

    unsigned int height = FreeImage_GetHeight(bitmap);
    unsigned int width = FreeImage_GetWidth(bitmap);

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            // get color
            FreeImage_GetPixelColor(bitmap, x, y, &c);


            float min = FLT_MAX;
            RGBQUAD selectedColor = colors[0];
            for (const RGBQUAD &col : colors) {
                float d = distance(c, col);
                if (min >= d) {
                    min = d;
                    selectedColor = col;
                }
            }
            FreeImage_SetPixelColor(bitmap, x, y, &selectedColor);
        }
    }

}


int argmax(vector<int> &probas) {
    int max = 0;
    for (unsigned int i = 0; i < probas.size(); ++i) {
        if (probas[i] > probas[max])
            max = i;
    }
    return max;
}


FIBITMAP *markov(FIBITMAP *bitmap) {
    RGBQUAD c;
    RGBQUAD c0;
    srand(0);

    unsigned int height = FreeImage_GetHeight(bitmap);
    unsigned int width = FreeImage_GetWidth(bitmap);


    for (unsigned int y = 1; y < height - 1; ++y) {
        for (unsigned int x = 1; x < width - 1; ++x) {
            // get color
            FreeImage_GetPixelColor(bitmap, x, y, &c);
            vector<int> probas = vector<int>(colors.size(), 0);

            for (int n = -1; n <= 1; ++n) {
                for (int m = -1; m <= 1; ++m) {
                    // get color
                    FreeImage_GetPixelColor(bitmap, x + n, y + m, &c0);
                    unsigned int i;
                    for (i = 0; i < colors.size(); ++i)
                        if (c0.rgbRed == colors[i].rgbRed && c0.rgbBlue == colors[i].rgbBlue && c0.rgbGreen == colors[i].rgbGreen)
                            break;
                    ++probas[i];
                }
            }
            FreeImage_SetPixelColor(bitmap, x, y, &colors[argmax(probas)]);
            probas.clear();
        }
    }
    return bitmap;
}


int main(int argc, char *argv[]) {

    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " INPUT OUTPUT" << std::endl;
        exit(1);
    }

    FreeImage_Initialise();

    FIBITMAP *bitmap = load_img(argv[1]);

    colorReduction(bitmap);

    for (int i = 0; i < 10; ++i)
        bitmap = markov(bitmap);

    save_img(bitmap, argv[2]);

    FreeImage_DeInitialise();
}
