#pragma once
#include "ImagePNM.h"

class ImagePPM: public ImagePNM
{
private:
public:
    ImagePPM(const char* filename);
    void grayscale() override;
    void monochrome() override{}
    void negative() override{}
    void rotate(int) override{}

};
