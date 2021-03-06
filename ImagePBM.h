#pragma once
#include "ImagePNM.h"

class ImagePBM: public ImagePNM
{
private:
    /* data */
public:
    ImagePBM(const char * filename);
    ImagePBM(const ImagePBM&);
    ~ImagePBM(){}
    
    void save(const char* filename) override;
    Image* createCopy()override;
    
    void grayscale() override{}
    void monochrome() override{}
    void negative() override;
    void rotate(int direction) override;
    bool** getPixels();
    void deletePixels(bool**&, int);
};

