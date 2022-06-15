#include <stdlib.h>
#include <cstring>
#include "ImagePNM.h"

ImagePNM::ImagePNM(const char* filename):Image(filename){
    
    char* tmp = new char[64];
    strncpy(tmp, data, 64);

    char* dimentions;
    type[0] = data[0];
    type[1] = data[1];

    firstPixelIndex = 5;

    dimentions = strtok(tmp+3, "\x0A");
    char* width = strtok(dimentions, " ");
    this->width = std::atoi(width);
    firstPixelIndex += strlen(width);

    char* height = strtok(NULL, " ");
    this->height = std::atoi(height);

    firstPixelIndex += strlen(height);

    if(!strcmp(type,"P5") || !strcmp(type,"P6")){
        char* maxPixelValue = strtok(tmp+firstPixelIndex, "\x0A");
        this->maxPixelValue = atoi(maxPixelValue);
        firstPixelIndex += 1 + strlen(maxPixelValue);
    }else{
        maxPixelValue = 1;
    }

    delete[] tmp;
}

ImagePNM::ImagePNM(const ImagePNM& image):Image(image),width(image.width),height(image.height),maxPixelValue(image.maxPixelValue),firstPixelIndex(firstPixelIndex){
    strcpy(type, image.type);
}

bool ImagePNM::CompareType(Image* image1, Image* image2){
    return ((ImagePNM*)image1)->type[0] == ((ImagePNM*)image2)->type[0] && ((ImagePNM*)image1)->type[1] == ((ImagePNM*)image2)->type[1];
}

ImagePNM& ImagePNM::operator=(const ImagePNM&image){
    Image::operator=(image);
    strcpy(type, image.type);
    width = image.width;
    height = image.height;
    maxPixelValue = image.maxPixelValue;
    firstPixelIndex = firstPixelIndex;
    return *this;
}
