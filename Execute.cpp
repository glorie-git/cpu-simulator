//
//  Execute.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Execute.hpp"

Execute::Execute(){
    
}

int Execute::execute(int operand1, int operand2, int dest, int immediate, int & address, int opcode){
    
    int result = 0;
    //for (int i = 0; i < ISSUE_WIDTH; i++) {
          switch (opcode) {
              case ADD :
                  result = operand1 + operand2;
                  break;
              case ADDI :
                  result = operand1 + immediate;
                break;
              case SUB :
                  result = operand1 - operand2;
                  break;
              case SUBI :
                  result = operand1 - immediate;
                  break;
              case MUL :
                  result = operand1 * operand2;
                  break;
              case MULI :
                  result = operand1 * immediate;
                  break;
              case DIV :
                  result = operand1 / operand2;
                  break;
              case DIVI :
                  result = operand1 / immediate;
                    break;
              case MOD :
                  result = operand1 % operand2;
                  break;
              case MODI :
                  result = operand1 % immediate;
                  break;
              case BNE :
                  result = dest - operand1;
                  if (result != 0)
                      address = (immediate-1);
                  break;
              case BEQ :
                  result = dest - operand1;
                  if (result == 0)
                      address = (immediate-1);
                  break;
              case MOV :
                  result = operand1;
                  break;
              case PARAM :
                  result = immediate;
                  break;
              case PRNT :
                  result = operand1;
                  break;

              default:
                  break;
          }
    //}
    
    return result;
}
