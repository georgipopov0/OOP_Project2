#pragma once
#include "myString.h"

class Image
{
private:
protected:
    myString filename;
    char *data;
    int dataSize;
  
public:
    Image(const char* filename);
    Image(const Image& image);
    virtual ~Image();

    myString getName()const;
    Image& operator =(const Image&); 

    virtual void save(const char*);
    virtual Image* createCopy() = 0;

    virtual void grayscale() = 0;
    virtual void monochrome() = 0;
    virtual void negative() = 0;
    virtual void rotate(int) = 0;
};