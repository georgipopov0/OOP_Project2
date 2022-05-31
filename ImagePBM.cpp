#include "ImagePBM.h"
#include <fstream> 
#include <cstring>

ImagePBM::ImagePBM(const char* filename):ImagePNM(filename){}
void ImagePBM::save(const char* filename){
    std::fstream out;
    out.open(filename, std::ios::trunc|std::ios::out);
    out << type << '\x0A' << width << '\x20' << height << '\x0A';
    out.write(data+firstPixelIndex, dataSize - firstPixelIndex);
    out.close();
}

void ImagePBM::negative(){
    for (int i = firstPixelIndex; i < dataSize; i++){
        unsigned char test = ((unsigned char)data[i]);
        unsigned char pixel = ~((unsigned char)data[i]);
        data[i] = (unsigned char)pixel;
    }
}

bool** ImagePBM::getPixels(){
    bool** pixels = new bool*[height];
    for (int i = 0; i < height; i++)
    {
        pixels[i] = new bool[width];
    }

    char* pixelsRaw = data + firstPixelIndex;

    for (int roll = 0; roll < height; roll++)
    {
        for (int col = 0; col < width; col++)
        {
            unsigned char test = pixelsRaw[(roll*width+col)/8];
            unsigned char test2 =(0x01<<(7-(roll*width+col)%8));
            unsigned char test1 = test2&pixelsRaw[(roll*width+col)/8];
            pixels[roll][col] = test2&test1;
        }
    }
    
    return pixels;
}

void ImagePBM::deletePixels(bool**& pixels, int size){
    for (int i = 0; i < size; i++)
    {
        delete[] pixels[i];
    }
    delete[] pixels;
}


void ImagePBM::rotate(int direction){
    char* pixels = data + firstPixelIndex;
    const unsigned int sizeBuffer = dataSize-firstPixelIndex; 
    char unsigned *tempBuffer = new unsigned char[dataSize-firstPixelIndex];

    bool** test = getPixels();
    bool** tmp = new bool*[width];
    for (int i = 0; i < width; i++)
    {
        tmp[i] = new bool[height];
    }


    if(direction<0)
    {
    for (int i=0; i<height; i++){
        for (int j=0;j<width; j++){
            tmp [j][i] = test[i][j];
        }
    }
    int tmp1 = height;
    height = width;
    width = tmp1;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {   
            if(tmp[y][x]){
                tempBuffer[(y*width+x)/8] = tempBuffer[(y*width+x)/8]|(0x01<<(7 - (y*width+x)%8));
            }
        }
        
    }
    
}
    else{
    for (int i=0; i<height; i++){
        for (int j=0;j<width; j++){
            tmp [j][height-1-i] = test[i][j];
        }
    }

    int tmp1 = height;
    height = width;
    width = tmp1;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {   
            if(tmp[y][x]){
                tempBuffer[(y*width+x)/8] = tempBuffer[(y*width+x)/8]|(0x01<<(7 - (y*width+x)%8));
            }
        }
        
    }
}
//     // Copy rotated pixels

    memcpy(pixels, tempBuffer, sizeBuffer);
    delete[] tempBuffer;
    deletePixels(test, width);
    deletePixels(tmp, height);
}
