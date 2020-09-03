//
//  RegisterFile.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef Register_hpp
#define Register_hpp

#include "HelperFunctions.hpp"

const int REG_MAX = 16;

#endif /* Register_hpp */

using namespace std;

struct reg {
    int dval = 0;
    int stat = 0;
};

class Register {
    
public:
    Register();
    ~Register();
    
    void set_dval(int val,int index);
    void set_stat(int val,int index);
    int size();
    int get_dval(int index);
    int get_stat(int index);
    void reset();
    
private:
    vector <reg*> registerFile;
};
