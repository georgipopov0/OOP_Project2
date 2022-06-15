#include "ImagePPM.h"
#include "ImagePGM.h"
#include "ImagePBM.h"
#include "Controller.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Controller controller;
    controller.init();
    // int *x = new int[3];
    // ImagePPM image("/mnt/c/Users/georg/Pictures/sample_1280×853.pgm");
    // image.makePictureLookCool();
    // image.save("test_cool.ppm");
    
    // ImagePGM image("/mnt/c/Users/georg/Pictures/PGM/sample_1280×853.pgm");
    // image.rotate(1);
    // image.save("/mnt/c/Users/georg/Pictures/PGM/test_right.pgm");
    
    // ImagePBM image("/mnt/c/Users/georg/Pictures/PBM/sample_1920×1280.pbm");
    // image.rotate(1);
    // image.save("/mnt/c/Users/georg/Pictures/PBM/test_rot_right.pbm");
    
    return 0;
}