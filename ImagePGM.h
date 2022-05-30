#pragma once
#include "ImagePNM.h"

class ImagePGM: public ImagePNM
{
private:
    /* data */
public:
    ImagePGM(const char* filename);
    ~ImagePGM(){}
    void save(const char* filename) override;
    void grayscale() override{}
    void monochrome() override;
    void negative() override;
    void rotate(int direction) override;
};