#include "ImagePPM.h"

int main(int argc, char const *argv[])
{
    // int *x = new int[3];
    ImagePPM image("sample1.ppm");
    image.grayscale();
    image.save("test.ppm");
    return 0;
}
