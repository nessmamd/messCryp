#include <iostream>
#include <string>
#include "hashfunction.h"

int main() {

    std::string userInput;
    std::cout << "Please write what you want to give the user" << std::endl;
    std::getline(std::cin, userInput); // Read the entire line, including spaces
    hashfunction hashObj(userInput);
//    std::cout << hashObj.changedMessage;

    return 0;
}
