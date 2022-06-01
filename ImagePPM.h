#pragma once
#include "ImagePNM.h"

class ImagePPM: public ImagePNM
{
private:
public:
    ImagePPM(const char* filename);
    ImagePPM(const ImagePPM&);

    void save(const char* fileName) override;
    Image* createCopy()override;
    
    void grayscale() override;
    void monochrome() override;
    void negative() override;
    void rotate(int) override;
    void makePictureLookCool();
};
