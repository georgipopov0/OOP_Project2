#pragma once
#include "EditingSession.h"

class ImageEditor
{
private:
    Vector<EditingSession> sessions;
    int currentSessionId;
public:
    ImageEditor(/* args */);

    void load(myString);
    void close(myString);
    void save(myString);
    void saveAs(myString, myString);
    void help();
    void exit();

    void grayscale();
    void monochrome();
    void negative();
    void rotate(int);

    void undo();
    void add(myString);
    void sessionInfo();
    void switchSession(int);
};

