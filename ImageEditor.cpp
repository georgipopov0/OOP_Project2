#include "ImageEditor.h"
#include <cstring>
#include <iostream>

/**
 * @brief Construct a new Image Editor:: Image Editor object
 * 
 */
ImageEditor::ImageEditor():sessions(Vector<EditingSession>()){}

/**
 * @brief Create a new session
 * 
 * @param image images to load in the session
 */
void ImageEditor::load(myString image){
    Vector<myString> files;
    char tmpBuffer[image.lenght()+1];
    memcpy(tmpBuffer,image.getChar(), image.lenght() + 1);
    char* tok = strtok(tmpBuffer, " ");    
    while (tok)
    {
        files.push(tok);
        tok = strtok(NULL, " ");
    }
    sessions.push(EditingSession(files));
    currentSessionId = sessions.size() - 1;
}

/**
 * @brief close an image
 * 
 * @param image 
 */
void ImageEditor::close(myString image){
    sessions.get(currentSessionId).close(image);
    std::cout << "Image " << image.getChar() << " closed\n";
}

/**
 * @brief save an image in the current session
 * 
 * @param image 
 */
void ImageEditor::save(myString image){
    sessions.get(currentSessionId).save(image);
    std::cout << "Image " << image.getChar() << " saved\n";
}

/**
 * @brief save image with new name
 * 
 * @param image 
 * @param filename 
 */
void ImageEditor::saveAs(myString image, myString filename){
    sessions.get(currentSessionId).saveAs(image, filename);
        std::cout << "Image " << image.getChar() << " saved as " << filename.getChar() <<"\n";
}

/**
 * @brief display  a help manual
 * 
 */
void ImageEditor::help(){
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

/**
 * @brief close the current session
 * 
 */
void ImageEditor::exit(){
    sessions.pop(currentSessionId);
    std::cout << "Session with ID: " << currentSessionId << " closed\n";
    currentSessionId = sessions.size() - 1;
    std::cout << "Current session: " << currentSessionId << std::endl;
}

/**
 * @brief graysale all images in the current session
 * 
 */
void ImageEditor::grayscale(){
    sessions.get(currentSessionId).grayscale();
}

/**
 * @brief monochrome all images in the session
 * 
 */
void ImageEditor::monochrome(){
    sessions.get(currentSessionId).monochrome();   
}

/**
 * @brief negative all images in the session
 * 
 */
void ImageEditor::negative(){
    sessions.get(currentSessionId).negative();
}

/**
 * @brief rotate all images in the sesiion
 * 
 * @param direction negative->counteclockwise positive->clockwise
 */
void ImageEditor::rotate(int direction){
    sessions.get(currentSessionId).rotate(direction);
}

/**
 * @brief undo last transformation in the session
 * 
 */
void ImageEditor::undo(){
    sessions.get(currentSessionId).undo();
}

/**
 * @brief add image to the session
 * 
 * @param image 
 */
void ImageEditor::add(myString image){
    sessions.get(currentSessionId).add(image);
}

/**
 * @brief display session info
 * 
 */
void ImageEditor::sessionInfo(){
    sessions.get(currentSessionId).sessionInfo();
}

/**
 * @brief switch to another session
 * 
 * @param sessionId 
 */
void ImageEditor::switchSession(int sessionId){
    currentSessionId = sessionId;
}
