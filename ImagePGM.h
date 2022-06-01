#pragma once
#include "ImagePNM.h"

class ImagePGM: public ImagePNM
{
private:
    /* data */
public:
    ImagePGM(const char* filename);
    ImagePGM(const ImagePGM&);
    ~ImagePGM(){}

    void save(const char* filename) override;
    Image* createCopy() override;

    void grayscale() override{}
    void monochrome() override;
    void negative() override;
    void rotate(int direction) override;
};