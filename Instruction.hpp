//
//  Instruction.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef Instruction_hpp
#define Instruction_hpp

#include "HelperFunctions.hpp"
//#include "Register.hpp"

#include <math.h>       /* pow */

using namespace std;

#endif /* Instruction_hpp */

const int INST_SIZE = 32;

class Instruction {
public:
    Instruction();
    ~Instruction();
    
    bool r_type,i_type, j_type, p_type;
    
    void decode(unsigned int);
    void print_instruction();
    void print_type();
    void set_instruction(string);
    void get_type();
    void r_type_fn();
    void i_type_fn();
    void j_type_fn();
    void p_type_fn();
    
    int get_type_();
    int get_src1();
    int get_src2();
    int get_immediate();
    int get_address();
    int get_opcode();
    int get_dest();
    
private:
    int instruction[INST_SIZE];
    int src1;
    int src2;
    int immediate;
    int address;
    int opcode;
    int dest;
    int type;
    int stringToBinary(int[],int);
};
