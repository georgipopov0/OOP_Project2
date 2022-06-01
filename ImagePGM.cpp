#include "ImagePGM.h"
#include <fstream>
#include <cstring>

ImagePGM::ImagePGM(const char* filename):ImagePNM(filename){}

ImagePGM::ImagePGM(const ImagePGM& image):ImagePNM(image){}

void ImagePGM::save(const char* filename){
    std::fstream out;
    out.open(filename, std::ios::trunc|std::ios::out);
    out << type << '\x0A' << width << '\x20' << height << '\x0A' << maxPixelValue << '\x0A';
    out.write(data+firstPixelIndex, dataSize - firstPixelIndex);
    out.close();
}

Image* ImagePGM::createCopy(){
    return new ImagePGM(*this);
}

void ImagePGM::monochrome(){
    for (int i = firstPixelIndex; i < dataSize; i++)
    {
        // int test = int(data)
        unsigned char pixel = (unsigned char)data[i];
        if(pixel >= this->maxPixelValue/2){
            pixel = maxPixelValue;
        }else{
            pixel = 0;
        }
        data[i] = (char)pixel;
    }
}

void ImagePGM::negative(){
    for (int i = firstPixelIndex; i < dataSize; i++){
        char pixel = maxPixelValue - ((unsigned char)data[i]);
        data[i] = (unsigned char)pixel;
    }
}

void ImagePGM::rotate(int direction){
    char* pixels = data + firstPixelIndex;
    const unsigned int sizeBuffer = width * height; 
    unsigned char *tempBuffer = new unsigned char[dataSize-firstPixelIndex];
    if(direction<0)
    {
    for (int y = 0, destinationColumn = 0; y < height; ++y, ++destinationColumn)
    {
        int offset = y * width;

        for (int x = 0; x < width; x++)
        {
                tempBuffer[(x * height + destinationColumn)] = pixels[(offset + x)];
        }
    }
}else{
    for (int y = 0, destinationColumn = height - 1; y < height; ++y, --destinationColumn)
    {
        int offset = y * width;

        for (int x = 0; x < width; x++)
        {
                tempBuffer[(x * height + destinationColumn)] = pixels[(offset + x)];
        }
    }
}
    // Copy rotated pixels

    memcpy(pixels, tempBuffer, sizeBuffer);
    delete[] tempBuffer;
    int tmp = height;
    height = width;
    width = tmp;
}
