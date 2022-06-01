#include <cstring>
#include <iostream>
#include "EditingSession.h"
#include "ImagePPM.h"
#include "ImagePGM.h"
#include "ImagePBM.h"

int EditingSession::findImageIndex(myString filename){
    for (int i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        if(!strcmp(filename.getChar(), images.get(i)->getName().getChar())){
            return i;
        }
    }
    return -1;
}

void EditingSession::backup(){
    for (int i = 0; i < images.size(); i++)
    {
        if(!backups.get(i)){
            continue;
        }
        delete backups.get(i);
        backups.get(i) = images.get(i)->createCopy();
    }
    
}

EditingSession::EditingSession(Vector<myString> files){
    for (int i = 0; i < files.size(); i++)
    {
        if(!strcmp(files.get(i).getChar()+files.get(i).lenght() - 3,"ppm")){
        images.push(new ImagePPM(files.get(i).getChar()));
        }
        else if(!strcmp(files.get(i).getChar()+files.get(i).lenght() - 3,"pgm")){
        images.push(new ImagePGM(files.get(i).getChar()));
        }
        else if(!strcmp(files.get(i).getChar()+files.get(i).lenght() - 3,"pbm")){
        images.push(new ImagePBM(files.get(i).getChar()));
        }
    }

    for (int i = 0; i < images.size(); i++)
    {
        backups.push(images.get(i)->createCopy());
    }
    
}

EditingSession::~EditingSession(){
    exit();
}

void EditingSession::close(myString filename){
    int i = findImageIndex(filename);
    if(i != -1){
        delete images.get(i);
        delete backups.get(i);
        images.push(nullptr,i);
        backups.push(nullptr, i);
        return;
    }
    throw "Image not found";
}

void EditingSession::save(myString filename){
    int i = findImageIndex(filename);
    if(i != -1){
        images.get(i)->save(images.get(i)->getName().getChar());
    }
    throw "Image not found";
}

void EditingSession::saveAs(myString filename, myString newName){
    int i = findImageIndex(filename);
    if(i != -1){
        images.get(i)->save(newName.getChar());
    }
    throw "Image not found";
}


//move that later
void EditingSession::help(){
    std::cout << "Comands:\n"
              << "grayscale         Applay grayscale filter to all images in the session\n"
              << "monochrome        Applay monochrome filter to all images in the session\n"
              << "negative          Applay negative filter to all images in the session\n"
              << "rotate            Rotate all images in the couurent session\n"
              << "undo              Revert chamges made from the last command\n"
              << "add <image>       Add image to the session\n"
              << "session info      Display information about the session\n"
              << "switch <session>  Swith to another session\n"
              << "save <image>      Save the specified image or ALL for all images\n"
              << "load <images>     Create a new session\n"
              << "close <image>     Close an image (changes are not saved)\n"
              << "help              Displays this manual\n"
              << "exit              Closses the current session (changes are not saved)\n"
              << "collage <direction> <image1> <image2> <outimage> Create collage\n"
              << "saveas <image> <filename> Save the image with a new filename\n";
}

void EditingSession::exit(){
    for (int i = 0; i < images.size(); i++)
    {
        delete images.get(i);
        delete backups.get(i);
    }
}

void EditingSession::grayscale(){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->grayscale();
    }
}

void EditingSession::monochrome(){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->monochrome();
    }
}


void EditingSession::negative(){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->negative();
    }
}

void EditingSession::undo(){
    for (int i = 0; i < backups.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        delete images.get(i);
        images.get(i) = backups.get(i)->createCopy();
    }
}

void EditingSession::add(myString filename){
    if(!strcmp(filename.getChar()+filename.lenght() - 3,"ppm")){
        images.push(new ImagePPM(filename.getChar()));
        }
    else if(!strcmp(filename.getChar()+filename.lenght() - 3,"pgm")){
        images.push(new ImagePGM(filename.getChar()));
        }
    else if(!strcmp(filename.getChar()+filename.lenght() - 3,"pbm")){
        images.push(new ImagePBM(filename.getChar()));
    }
    backups.push(images.get(images.size()-1)->createCopy());
}


void EditingSession::sessionInfo(){
    std::cout << "Name of images in the session:";
    for (int i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        std::cout << images.get(i)->getName().getChar();
    }
    std::cout << "\n";
    // implemetn chanes vector....
}