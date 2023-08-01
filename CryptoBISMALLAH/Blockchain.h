//
// Created by Nessma Mohdy on 2023-07-26.
//

#ifndef CRYPTOBISMALLAH_BLOCKCHAIN_H
#define CRYPTOBISMALLAH_BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include "Block.h"
using namespace std;


class Blockchain{
public:
    //i think this is the function that we use to create the linking between the two
    Blockchain();

    void AddBlock(Block bNew);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

#endif //CRYPTOBISMALLAH_BLOCKCHAIN_H

