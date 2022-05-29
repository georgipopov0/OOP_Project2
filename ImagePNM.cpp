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
    char* with = strtok(dimentions, " ");
    this->with = std::atoi(with);
    firstPixelIndex += strlen(with);

    char* hight = strtok(NULL, " ");
    this->hight = std::atoi(hight);

    firstPixelIndex += strlen(hight);

    if(!strcmp(type,"P5") || !strcmp(type,"P6")){
        char* maxPixelValue = strtok(tmp+firstPixelIndex, "\x0A");
        this->maxPixelValue = atoi(maxPixelValue);
        firstPixelIndex += 1 + strlen(maxPixelValue);
    }else{
        maxPixelValue = 1;
    }

    delete[] tmp;
}