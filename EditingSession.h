#pragma once
#include "Image.h"
#include "myString.h"
#include "myVector.h"

class EditingSession
{
private:
    Vector<Image*> images;
    Vector<Image*> backups;

    int findImageIndex(myString);
    void backup();

public:
    EditingSession(Vector<myString>);
    ~EditingSession();
    
    EditingSession& operator =(const EditingSession&);

    void close(myString);
    void save(myString);
    void saveAs(myString, myString);
    void help();
    void exit();

    void grayscale();
    void monochrome();
    void negative();
    void rotate(int direction);

    void undo();
    void add(myString);
    void sessionInfo();
};
