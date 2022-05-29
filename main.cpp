#include "ImagePPM.h"

int main(int argc, char const *argv[])
{
    // int *x = new int[3];
    ImagePPM image("sample1.ppm");
    image.makePictureLookCool();
    image.save("test_cool.ppm");
    return 0;
}