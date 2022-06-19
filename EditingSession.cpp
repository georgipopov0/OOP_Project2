#include <cstring>
#include <iostream>
#include "EditingSession.h"
#include "ImagePPM.h"
#include "ImagePGM.h"
#include "ImagePBM.h"

/**
 * @brief Find image by name
 * 
 * @param filename 
 * @return int location of the image
 */
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

/**
 * @brief backup all images in the backup array
 * 
 */
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

/**
 * @brief Construct a new Editing Session:: Editing Session object
 * 
 * @param files 
 */
EditingSession::EditingSession(Vector<myString> files){

    for (int i = 0; i < files.size(); i++)
    {
        if(!strcmp(files.get(i).getChar()+files.get(i).lenght() - 3,"ppm")){
        images.push(new ImagePPM(files.get(i).getChar()));
        std::cout << "Image \"" << files.get(i).getChar() << "\" added\n";
        }
        else if(!strcmp(files.get(i).getChar()+files.get(i).lenght() - 3,"pgm")){
        images.push(new ImagePGM(files.get(i).getChar()));
        std::cout << "Image \"" << files.get(i).getChar() << "\" added\n";
        }
        else if(!strcmp(files.get(i).getChar()+files.get(i).lenght() - 3,"pbm")){
        images.push(new ImagePBM(files.get(i).getChar()));
        std::cout << "Image \"" << files.get(i).getChar() << "\" added\n";
        }
        else{
            throw "Bad image type";
        }
    }

    for (int i = 0; i < images.size(); i++)
    {
        backups.push(images.get(i)->createCopy());
    }
    
}

/**
 * @brief Destroy the Editing Session:: Editing Session object
 * 
 */
EditingSession::~EditingSession(){
    exit();
}

/**
 * @brief 
 * 
 * @param session 
 * @return EditingSession& 
 */
EditingSession& EditingSession::operator =(const EditingSession& session){
    
    exit();

    for (int i = 0; i < session.images.size(); i++)
    {
        images.push(session.images.get(i)->createCopy(),i);
    }

    for (int i = 0; i < session.backups.size(); i++)
    {
        backups.push(session.backups.get(i)->createCopy(),i);
    }
    return *this;
}

/**
 * @brief close an image
 * 
 * @param filename 
 */
void EditingSession::close(myString filename){
    int i = findImageIndex(filename);
    if(i != -1){
        delete images.get(i);
        delete backups.get(i);
        images.push(nullptr,i);
        backups.push(nullptr, i);
        std::cout << "Image \"" << images.get(i)->getName().getChar() << "\" closed\n";
        return;
    }
    throw "Image not found";
}

/**
 * @brief Save an image
 * 
 * @param filename name of the image
 */
void EditingSession::save(myString filename){
    int i = findImageIndex(filename);
    if(i != -1){
        images.get(i)->save(images.get(i)->getName().getChar());
        std::cout << "Image \"" << images.get(i)->getName().getChar() << "\" saved\n";
    }
    throw "Image not found";
}

/**
 * @brief Save an image with a specified name
 * 
 * @param filename name of the image
 * @param newName name to be saved as
 */
void EditingSession::saveAs(myString filename, myString newName){
    int i = findImageIndex(filename);
    if(i != -1){
        images.get(i)->save(newName.getChar());
        std::cout << "Image \"" << images.get(i)->getName().getChar() << "\" saved as \"" << newName.getChar() << "\"" << std::endl;
    }
    throw "Image not found";
}

/**
 * @brief close the editing session
 * 
 */
void EditingSession::exit(){
    for (int i = 0; i < images.size(); i++)
    {
        delete images.get(i);
        delete backups.get(i);
    }   
}

/**
 * @brief grayscale all images in the session
 * 
 */
void EditingSession::grayscale(){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->grayscale();
    }
    pendingTransformations.push("grayscale");
}

/**
 * @brief monochrome all images in the session
 * 
 */
void EditingSession::monochrome(){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->monochrome();
    }
    pendingTransformations.push("monochrome");
}

/**
 * @brief negative all the images in the session
 * 
 */
void EditingSession::negative(){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->negative();
    }
    pendingTransformations.push("negative");
}

/**
 * @brief rotate all the images in the session
 * 
 * @param direction if positive rotate right if negative rotate left
 */
void EditingSession::rotate(int direction){
    backup();
    for (int  i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        images.get(i)->rotate(direction);
    }
    pendingTransformations.push("rotate");
}

/**
 * @brief undo last transformation in the session
 * 
 */
void EditingSession::undo(){
    for (int i = 0; i < backups.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        delete images.get(i);
        images.get(i) = backups.get(i)->createCopy();
    }
    pendingTransformations.pop();
}

/**
 * @brief add iamge to the session
 * 
 * @param filename 
 */
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
    std::cout << "Image \"" << filename.getChar() << "\" added\n";
}

/**
 * @brief display info about the session
 * 
 */
void EditingSession::sessionInfo(){
    std::cout << "Name of images in the session:";
    for (int i = 0; i < images.size(); i++)
    {
        if(!images.get(i)){
            continue;
        }
        std::cout << images.get(i)->getName().getChar() << "\n";
        std::cout << "Pending transformations: " ;
        for (int i = 0; i < pendingTransformations.size(); i++)
        {
            std::cout << "," <<pendingTransformations.get(i).getChar();
        }
        
    }

    std::cout << std::endl;

    for (int i = 0; i < pendingTransformations.size(); i++)
    {
        std::cout << pendingTransformations.get(i).getChar() << " ,";
    }
    
    std::cout << std::endl;
}