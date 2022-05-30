#include <iostream>
#include <fstream>
#include "Image.h"

Image::Image(const char* filename){
    std::ifstream file;
    file.open(filename, std::ios::binary);

    file.seekg(0, std::ios::end);
    dataSize = file.tellg();
    file.seekg(0, std::ios::beg);

    this->data = new char[dataSize];
    file.read(data, dataSize);
    file.close();
}

Image::~Image(){
    delete[] data;
}

void Image::save(const char* filename){
    std::fstream fs;
    fs.open(filename, std::fstream::out | std::fstream::trunc);
    fs.write(data,dataSize);
    fs.close();
}