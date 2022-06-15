#include "Controller.h"
#include <iostream>
#include <cstring>

void getCommand(Vector<myString>& argv){
    char command[64];
    for (int i = 0;; i++)
    {
        std::cin >> command;
        if (std::cin.peek() == '\n') {
            break;
        }
        argv.get(i) = command;
    }
}

void Controller::init(){
    Vector<myString> command;
    while (true)
    {
        try
        {
            std::cout << "> ";
            getCommand(command);
            if(!strcmp(command.get(0).getChar(), "load")){
                editor.load(command.get(1));
            }
            else if(!strcmp(command.get(0).getChar(), "close")){
                editor.close(command.get(1));
            }
            else if(!strcmp(command.get(0).getChar(), "save")){
                editor.save(command.get(1));
            }
            else if(!strcmp(command.get(0).getChar(), "saveas")){
                editor.saveAs(command.get(1), command.get(2));
            }
            else if(!strcmp(command.get(0).getChar(), "help")){
                editor.help();
            }
            else if(!strcmp(command.get(0).getChar(), "exit_session")){
                editor.exit();
            }
            else if(!strcmp(command.get(0).getChar(), "exit")){
                break;
            }
            else if(!strcmp(command.get(0).getChar(), "grayscale")){
                editor.grayscale();
            }
            else if(!strcmp(command.get(0).getChar(), "monochrome")){
                editor.monochrome();
            }
            else if(!strcmp(command.get(0).getChar(), "negative")){
                editor.negative();
            }
            
        }
        catch(const char* message)
        {
            std::cerr << message << std::endl;
        }
        
    }
    
}