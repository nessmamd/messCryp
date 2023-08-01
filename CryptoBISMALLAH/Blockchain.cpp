//
// Created by Nessma Mohdy on 2023-07-27.
//
#include "Blockchain.h"

Blockchain::Blockchain(){
//    the gensis block is the starting point
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 2;
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

void Blockchain::AddBlock(Block bNew){
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}