#pragma once
#include "ImageEditor.h"

class Controller
{
private:
    ImageEditor editor;

    void getCommand(Vector<myString>& argv);


public:
    void init();
};

