//
// Created by Nessma Mohdy on 2023-07-27.
//

#include "Block.h"
#include "sha256.h"
#include <sstream>

//constructor, creating the defintion for it
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn){
    _nNonce = -1;
    _tTime = time(nullptr);
}

string Block::GetHash(){
    return _sHash;
}

//Proof of Work is when it checks if the hash is valid or not, this is where the mining process occurs because the right hash must be created
// the number of zeros at the beginnning of the hash is equal to or greater than the diffcuilty level

void Block::MineBlock(uint32_t nDifficulty){
    //creating the right crypto hash
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i){
        cstr[i] = '0';

    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    //this is the proof of work, the reason we do this is so we can check that it is an acc chain
    // for your own it could be letters or something
    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while(_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl; 
}
inline string Block::_CalculateHash() const {
    stringstream ss;

    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
    cout  << ss.str();
    return sha256(ss.str());
}
