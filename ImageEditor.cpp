#include "ImageEditor.h"
#include <cstring>
#include <iostream>

ImageEditor::ImageEditor():sessions(Vector<EditingSession>()){}

void ImageEditor::load(myString image){
    Vector<myString> files;
    char tmpBuffer[image.lenght()+1];
    memcpy(tmpBuffer,image.getChar(), image.lenght() + 1);
    char* tok = strtok(tmpBuffer, " ");
    while (!tok)
    {
        files.push(tok);
    }
    sessions.push(EditingSession(files));
    currentSessionId = sessions.size() - 1;
    std::cout << "Session with ID: 1 started\n";
}

void ImageEditor::close(myString image){
    sessions.get(currentSessionId).close(image);
}

void ImageEditor::save(myString image){
    sessions.get(currentSessionId).save(image);
}

void ImageEditor::saveAs(myString image, myString filename){
    sessions.get(currentSessionId).saveAs(image, filename);
}

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

void ImageEditor::exit(){
    sessions.pop(currentSessionId);
    std::cout << "Session with ID: " << currentSessionId << " closed\n";
    currentSessionId = sessions.size();
    std::cout << "Current session: " << currentSessionId << std::endl;
}

void ImageEditor::grayscale(){
    sessions.get(currentSessionId).grayscale();
}

void ImageEditor::monochrome(){
    sessions.get(currentSessionId).monochrome();   
}

void ImageEditor::negative(){
    sessions.get(currentSessionId).negative();
}

void ImageEditor::rotate(int direction){
    sessions.get(currentSessionId).rotate(direction);
}

void ImageEditor::undo(){
    sessions.get(currentSessionId).undo();
}

void ImageEditor::add(myString filename){
    sessions.get(currentSessionId).add(filename);
}

void ImageEditor::sessionInfo(){
    sessions.get(currentSessionId).sessionInfo();
}

void ImageEditor::switchSession(int sessionId){
    currentSessionId = sessionId;
}
