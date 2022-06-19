#include "Controller.h"
#include <iostream>
#include <cstring>


/**
 * @brief Get and parse command from stdin
 * 
 * @param argv [0] is the name of the command and the rest are arguments
 */
void Controller::getCommand(Vector<myString>& argv){
    char command[64];
    for (int i = 0;; i++)
    {
        std::cin >> command;
        argv.push(command, i);
        if (std::cin.peek() == '\n') {
            break;
        }
    }
}

// Starts the user interface
void Controller::init(){
    Vector<myString> command;
    while (true)
    {
        try
        {
            std::cout << "> ";
            Controller::getCommand(command);
            if(!strcmp(command.get(0).getChar(), "load")){
                // myString test = command.get(1);
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