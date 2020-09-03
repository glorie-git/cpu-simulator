//
//  Pipeline.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef Pipeline_hpp
#define Pipeline_hpp

#include <stdio.h>
#include "HelperFunctions.hpp"
#include "Memory.hpp"
#include "Register.hpp"
#include "IQueue.hpp"
#include "Execute.hpp"
#include "Statistics.hpp"
//#include "Instruction.hpp"
//#include "FetchUnit.hpp"


#endif /* Pipeline_hpp */

struct rob_inst {
    int vald_bit = 0;
    unsigned int instruction = 0;
    int ROB_ID = NULL;
};

class Pipeline : public Execute {
public:
    Pipeline();
    ~Pipeline();
    
    void initiate_pipeline(string);
    void initiate_pipeline();
    void fetch();
    void commit();
    void execute();
    void addinst_rob(rob_inst*);
    bool branchDetected;
    void print_inst(int opcode,int dest, int reg1, int reg2, int immediate, int type);
    bool isempty_IQ();
    bool isempty_ROD();
    void reset();
    void start(bool);
    void print_stats();
    
private:
    Statistics * stats = new Statistics;
    IQueue * IQ = new IQueue;
    Memory * memory = new Memory(FETCH_WIDTH);
    Register * registerFile = new Register;
    vector <rob_inst*> reorderBuffer;
    int PC;
    int ROB_ID;
    int already_fecthed;
    int committed;
    string filename;
    bool done;
    bool debug;
};

