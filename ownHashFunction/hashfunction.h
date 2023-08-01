//
// Created by Nessma Mohdy on 2023-07-31.
//

#ifndef OWNHASHFUNCTION_HASHFUNCTION_H
#define OWNHASHFUNCTION_HASHFUNCTION_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class hashfunction{
public:
    //Block Prev Hash Value;
    std::string changedMessage;
    hashfunction(std::string userinput);
    std::vector<std::string> sectors;
    map<char, int>hillCipher;

private:
    std::string secreteMessage;
    void processingMessage();
    void encryptingMessage();
    char findingLetter(int respLetter);
    int mainKey[3][3];
    int mo3;
};
#endif //OWNHASHFUNCTION_HASHFUNCTION_H
