#pragma once
#include "Image.h"

class ImagePNM: public Image
{
protected:
    char type[2];
    int with;
    int hight;
    int maxPixelValue;
    int firstPixelIndex;
public:
    ImagePNM(const char*);
};
