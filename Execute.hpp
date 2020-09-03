//
//  Execute.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef Execute_hpp
#define Execute_hpp

#include "HelperFunctions.hpp"

#endif /* Execute_hpp */

class Execute {
    
public:
    Execute();
    
    int execute(int operand1,int oprend2,int dest,int immediate,int&address, int opcode);
};
