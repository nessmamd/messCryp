//
// Created by Nessma Mohdy on 2023-07-31.
//

#include <string>
#include <typeinfo>
#include <cmath>
#include <algorithm>
#include <random>
#include "hashfunction.h"
using namespace std;

hashfunction::hashfunction(std::string userinput) {
    secreteMessage = userinput;
    processingMessage();
}

void hashfunction::processingMessage(){
    //creating the variables
    int totalSize;
    char *pointing;

    //doing the cleaning
    totalSize = secreteMessage.length();
    secreteMessage.erase(std::remove_if(secreteMessage.begin(), secreteMessage.end(), ::isspace), secreteMessage.end());

    //creating the allocation
    char* charArray = new char[secreteMessage.length() + 1];
    pointing = charArray;
    std::strcpy(charArray, secreteMessage.c_str());

    //creating the sections
    mo3 = std::round(totalSize/3);
    for (int i = 1; i <= mo3; i++) {
        std::string newString(pointing, 3);

        for (char& letter : newString) {
            if (letter == '\0') {
                letter = 'a';
            }
        }
        sectors.push_back(newString);
        pointing += 3;
    }

    for(int y = 0; y <= 25; y++) {
        hillCipher[char(97 + y)] = y;
    }

    //creating the key that will be used for that time
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 25);
    for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
            mainKey[p][q] = distribution(gen);
        }
    }
    encryptingMessage();
}

void hashfunction::encryptingMessage(){
    int mat[mo3][3];
    for(int l = 0; l < mo3; l++){
        std::string reference = sectors[l];
        for(int p = 0; p < 3; p++){
            mat[l][p] = hillCipher[reference[p]];
        }
    }

    for(int x = 0; x < mo3; x++){
        for(int z = 0; z<3; z++){
            int sumOk = 0;
            for(int p = 0; p<3; p++){
                sumOk += ((mainKey[z][p]*mat[x][p]) % 26);
            }
            changedMessage += std::to_string(sumOk);
        }
    }
}
