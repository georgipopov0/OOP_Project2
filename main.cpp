#include "ImagePPM.h"
#include "ImagePGM.h"

int main(int argc, char const *argv[])
{
    // int *x = new int[3];
    // ImagePPM image("/mnt/c/Users/georg/Pictures/sample_1280×853.pgm");
    // image.makePictureLookCool();
    // image.save("test_cool.ppm");
    
    ImagePGM image("/mnt/c/Users/georg/Pictures/PGM/sample_1280×853.pgm");
    image.rotate(1);
    image.save("/mnt/c/Users/georg/Pictures/PGM/test_right.pgm");
    
    
    return 0;
}