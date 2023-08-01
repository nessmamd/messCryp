//
// Created by Nessma Mohdy on 2023-07-26.
//

#ifndef CRYPTOBISMALLAH_BLOCK_H
#define CRYPTOBISMALLAH_BLOCK_H
#include <cstdint>
#include <iostream>
using namespace std;

class Block{
public:
    string sPrevHash;
    // this is a constructor that takes in two arguments to create the block
    //the parameters are passed as a reference modifer that cannot be changed

    Block(uint32_t nIndexIn, const string &sDataIn);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    // once the hash of the object is created we dont want to make any changes to it
    string _CalculateHash() const;
};

#endif //CRYPTOBISMALLAH_BLOCK_H

