#include "ImagePPM.h"
#include <iostream>

ImagePPM::ImagePPM(const char* filename):ImagePNM(filename){
}

void ImagePPM::grayscale(){
    for (int i = firstPixelIndex; i < dataSize; i+=3)
    {
        // int test = int(data)
        unsigned char gray = ((unsigned char)(data[i]) + (unsigned char)data[i+1] + (unsigned char)data[i+2])/3;
        data[i] = (char)gray;
        data[i+1] = (char)gray;
        data[i+2] = (char)gray;
    }
}
