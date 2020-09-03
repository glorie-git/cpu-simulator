//
//  HelperFunctions.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef HelperFunctions_hpp
#define HelperFunctions_hpp

#include <stdio.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

const int FETCH_WIDTH = 3;
const int ISSUE_WIDTH = 3;
const int COMMIT_WIDTH = 3;

#define ADD     0
#define SUB     1
#define MUL     2
#define DIV     3
#define MOD     4
#define BEQ     5
#define BNE     6
#define MOV     7
#define PRNT    8

#define ADDI    9
#define SUBI    10
#define MULI    11
#define DIVI    12
#define MODI    13
#define PARAM   14

#define R_TYPE   1
#define J_TYPE   2
#define I_TYPE   3
#define P_TYPE   4

#endif /* HelperFunctions_hpp */

