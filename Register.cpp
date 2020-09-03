//
//  Register.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Register.hpp"

Register::Register(){
    registerFile.reserve(REG_MAX);
    
    for (int i = 0; i < 16; i++){
        reg * r = new reg;
        registerFile.push_back(r);
        registerFile[i]->dval = 0;
        registerFile[i]->stat = 1;
    }
}

Register::~Register(){
    
}

void Register::set_dval (int val, int index){
    registerFile[index]->dval = val;
}

void Register::set_stat (int val, int index){
    registerFile[index]->stat = val;
}

int Register::size(){
    return registerFile.size();
}


int Register::get_dval (int index){
    return registerFile[index]->dval;
}

int Register::get_stat (int index){
    return registerFile[index]->stat;
}

void Register::reset(){
    registerFile.clear();
}

