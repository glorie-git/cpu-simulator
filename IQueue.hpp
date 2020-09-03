//
//  IQueue.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef IQueue_hpp
#define IQueue_hpp

#include "HelperFunctions.hpp"
#include "Instruction.hpp"

#endif /* IQueue_hpp */

struct instQ {
    int dest = 0;
    int operation = 0;
    int valid1 = 0;
    int src1 = 0;
    int valid2 = 0;
    int src2 = 0;
    int immediate = 0;
    int ROB_ID = 0;
    int type = 0;
};
typedef instQ * instQPtr;


class IQueue {
    
public:
    IQueue();
    ~IQueue();
    //const int col = 6;
    //const int row = FETCH_WIDTH;
    void addInst(instQ*);
    void set_valid1(int, instQ);
    void set_operation(int, instQ);
    void set_valid2(int, instQ);
    void set_src1(int, instQ);
    void set_src2(int, instQ);
    void set_immediate(int, instQ);
    void set_dest(int, instQ);
    void set_rob_id(int, instQ);
    void printIQ();
    vector < instQ* > iqueue;
};
