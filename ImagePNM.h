#pragma once
#include "Image.h"
#include <fstream>

class ImagePNM: public Image
{
protected:
    char type[2];
    int width;
    int height;
    int maxPixelValue;
    int firstPixelIndex;
public:
    ImagePNM(const char*);
    ImagePNM(const ImagePNM&);
    bool CompareType(Image*, Image*);

    ImagePNM& operator=(const ImagePNM&);
    };

