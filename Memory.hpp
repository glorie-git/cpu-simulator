//
//  Memory.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef Memory_hpp
#define Memory_hpp

#include "HelperFunctions.hpp"

#endif /* Memory_hpp */

class Memory {
    
public:
    
    Memory();
    Memory(string fname){
        file_name = fname;
    }

    Memory(int MAX_SIZE){
        instruction_memory.reserve(MAX_SIZE);
        num_instrs = 0;
    }
    
    Memory(int MAX_SIZE, string fname){
        instruction_memory.reserve(MAX_SIZE);
        file_name = fname;
        num_instrs = 0;
    }
    
    int get_num_instrs();
    unsigned int get_instr(int);
    void read_file();
    void read_file(string fname);
    string file_name;
    unsigned int string2unsigned(string);
    void reset();
    int size();
    
    private :
        int num_instrs;
        vector <unsigned int> instruction_memory;
};


