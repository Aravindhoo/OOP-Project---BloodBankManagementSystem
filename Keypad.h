#ifndef KEYPAD_H
#define KEYPAD_H

#include <string>

// Keypad reads user input from the terminal.
class Keypad
{
public:
    int getInput();
    std::string getStringInput();
    double getDoubleInput();
};

#endif
