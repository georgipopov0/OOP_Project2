#include "ImagePPM.h"
#include <iostream>
#include <fstream>
#include <cstring>

ImagePPM::ImagePPM(const char* filename):ImagePNM(filename){
}

void ImagePPM::save(const char* filename){
    std::fstream out;
    out.open(filename, std::ios::trunc|std::ios::out);
    out << type << '\x0A' << width << '\x20' << height << '\x0A' << maxPixelValue << '\x0A';
    out.write(data+firstPixelIndex, dataSize - firstPixelIndex);
    out.close();
}

void ImagePPM::grayscale(){
    for (int i = firstPixelIndex; i < dataSize; i+=3)
    {
        // int test = int(data)
        unsigned char gray = ((unsigned char)(data[i]) + (unsigned char)data[i+1] + (unsigned char)data[i+2])/3;
        data[i] = (char)gray;
        data[i+1] = (char)gray;
        data[i+2] = (char)gray;
    }
}

void ImagePPM::monochrome(){
        for (int i = firstPixelIndex; i < dataSize; i+=3)
    {
        // int test = int(data)
        unsigned char gray = ((unsigned char)(data[i]) + (unsigned char)data[i+1] + (unsigned char)data[i+2])/3;
        if(gray >= this->maxPixelValue/2){
            gray = 255;
        }else{
            gray = 0;
        }
        data[i] = (char)gray;
        data[i+1] = (char)gray;
        data[i+2] = (char)gray;
    }
}

void ImagePPM::negative(){
    for (int i = firstPixelIndex; i < dataSize; i++){
        char pixel = maxPixelValue - ((unsigned char)data[i]);
        data[i] = (unsigned char)pixel;
    }
}

void ImagePPM::rotate(int direction){
    char* pixels = data + firstPixelIndex;
    const unsigned int sizeBuffer = width * height * 3; 
    unsigned char *tempBuffer = new unsigned char[dataSize-firstPixelIndex];
    if(direction<0)
    {
    for (int y = 0, destinationColumn = 0; y < height; ++y, ++destinationColumn)
    {
        int offset = y * width;

        for (int x = 0; x < width; x++)
        {
            for (int i = 0; i < 3; i++)
                tempBuffer[(x * height + destinationColumn) * 3 + i] = pixels[(offset + x) * 3 + i];
        }
    }
}else{
    for (int y = 0, destinationColumn = height - 1; y < height; ++y, --destinationColumn)
    {
        int offset = y * width;

        for (int x = 0; x < width; x++)
        {
            for (int i = 0; i < 3; i++)
                tempBuffer[(x * height + destinationColumn) * 3 + i] = pixels[(offset + x) * 3 + i];
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

void ImagePPM::makePictureLookCool(){
    for (int i = firstPixelIndex; i < dataSize; i++){
        char pixel = maxPixelValue - ((unsigned char)data[i]);
        if(pixel<0){
            pixel*=-1;
        }
        data[i] = (unsigned char)pixel;
    }
}
