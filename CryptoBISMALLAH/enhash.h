//
// Created by Nessma Mohdy on 2023-07-31.
//

#ifndef CRYPTOBISMALLAH_ENHASH_H
#define CRYPTOBISMALLAH_ENHASH_H
#include "Block.h"
#include <vector>

using namespace std;

class enhash{
public:
    //still to do this
    //Block prevouisHashValue;
    std::vector<char> changedMessage;
    enhash(vector<char> userinput);


private:
    std::vector<char> secretMessage;
    //this should create some cool decyphering thing
    void processingMessage();
    //function to include the prev block hash values, takes the ones at the center value
    //function to create the verification values aka the zeros at the start
    //function to do the full hash.. or encryption method...? just google it and find the methods that are
};

#endif //CRYPTOBISMALLAH_ENHASH_H
