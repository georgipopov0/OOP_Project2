#include <iostream>
#include <fstream>
#include <cstring>
#include "Image.h"


/**
 * @brief Construct a new Image:: Image object
 * 
 * @param filename image to load
 */
Image::Image(const char* filename){
    std::ifstream file;
    file.open(filename, std::ios::binary);
    if(!file){
        throw "Couldnt open the file";
    }
    file.seekg(0, std::ios::end);
    dataSize = file.tellg();
    file.seekg(0, std::ios::beg);

    this->data = new char[dataSize];
    file.read(data, dataSize);
    file.close();
}

/**
 * @brief Construct a new Image:: Image object
 * 
 * @param image 
 */
Image::Image(const Image& image){
    filename = image.filename;
    dataSize = image.dataSize;
    data = new char[dataSize];
    memcpy(data, image.data, dataSize);
}

/**
 * @brief Destroy the Image:: Image object
 * 
 */
Image::~Image(){
    delete[] data;
}

/**
 * @brief 
 * 
 * @return myString 
 */
myString Image::getName()const{
    return filename;
}

/**
 * @brief 
 * 
 * @param image 
 * @return Image& 
 */
Image& Image::operator =(const Image& image){
    filename = image.filename;
    dataSize = image.dataSize;
    delete data;
    data = new char[dataSize];
    memcpy(data, image.data, dataSize);
    return *this;
} 

/**
 * @brief save the iamge
 * 
 * @param filename 
 */
void Image::save(const char* filename){
    std::fstream fs;
    fs.open(filename, std::fstream::out | std::fstream::trunc);
    fs.write(data,dataSize);
    fs.close();
}