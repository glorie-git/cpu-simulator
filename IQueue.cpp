//
//  IQueue.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "IQueue.hpp"

IQueue::IQueue(){
    
}

IQueue::~IQueue(){
    
}

void IQueue::addInst(instQ *inst){
    iqueue.push_back(inst);
}

void IQueue::set_valid1(int x, instQ inst){
    inst.valid1 = x;
}

void IQueue::set_valid2(int x, instQ inst){
    inst.valid2 = x;
}

void IQueue::set_src1(int x, instQ inst){
    inst.src1 = x;
}

void IQueue::set_src2(int x, instQ inst){
    inst.src2 = x;
}

void IQueue::set_dest(int x, instQ inst){
    inst.dest = x;
}

void IQueue::set_rob_id(int x, instQ inst){
    inst.ROB_ID = x;
}

void IQueue::printIQ(){
    vector < instQ * > :: iterator it = iqueue.begin();
    int i = 0;
    cout << "\n\n------------- Instruction Queue   -------------\n";
    cout << setw(10) << left << "Dest" << setw(10) << "V" << setw(10) << "Src1" << setw(10) << "V" << setw(10) << "Src2" << setw(10) << "Immediate\n";
    
    for (; it != iqueue.end(); it++){
        cout << setw(10) << left << iqueue[i]->dest << setw(10) << iqueue[i]->valid1 << setw(10) << iqueue[i]->src1 << setw(10) << iqueue[i]->valid2 << setw(10) << iqueue[i]->src2 << setw(10) << iqueue[i]->immediate << endl;
        i++;
    }
}

void set_operation(int x, instQ inst){
    inst.operation = x;
}

void set_immediate(int x, instQ inst){
    inst.immediate = x;
}
