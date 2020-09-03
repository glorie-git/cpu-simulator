//
//  Instruction.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Instruction.hpp"

Instruction::Instruction(){
    for (int i = 0; i < INST_SIZE; i++){
        instruction[i] = 0;
    }
    r_type = false;
    i_type = false;
    j_type = false;
    p_type = false;
    src1 = 0;
    src2 = 0;
    immediate = 0;
    address = 0;
    opcode = 0;
    dest = 0;
    type = 0;
}
Instruction::~Instruction()
{
    
}

void Instruction::decode(unsigned int xx)
// Precondition: string is passed as parameter, string should hold unsigned int
// Postcondition: converts string to unsigned in and then returns a char * of the
{
    //int number ;
    //char * str = new char[8] ; // to store converted unsigned char
    unsigned int remainder = 0;
    
    //number = (int) k ; // stores k's integer equivalent to variable number
    for (int i = 31 ; i >= 0; i--)
    {
        remainder = (xx % 2) ; // produces the remainder
        instruction[i] = remainder; // stores the remainder into str pointer array
        xx = xx / 2 ; // divides number by 2 and uses this result to calculate the next remainder
    }
    
    get_type();
    
    if ( r_type )
        r_type_fn();
    else if ( i_type )
        i_type_fn();
    else if ( j_type )
        j_type_fn();
    else if ( p_type )
        p_type_fn();
}

int Instruction::stringToBinary(int xx[],int len)
{
    int num = 0, count = 0 ;
    for (int i = len; i >= 0; --i)
    {
        if ( xx[i] == 1 )
        {
            num += pow (2 , count) ;
        }
        count ++ ;
    }
    return num ;
}

void Instruction::print_instruction(){
    for (int i = 0; i < INST_SIZE; i++){
        cout << instruction[i];
        if ( i == 1 )
        { cout << " ";}
        if ( i == 5 )
        {cout << " ";}
        if ( i == 10 )
        {cout << " ";}
        if ( i == 15 )
        {cout << " ";}
    }
}

int Instruction::get_src1(){
    return src1;
}

int Instruction::get_src2(){
    return src2;
}

int Instruction::get_immediate(){
    return immediate;
}
int Instruction::get_address(){
    return address;
}
int Instruction::get_opcode(){
    return opcode;
}
int Instruction::get_dest(){
    return dest;
}


void Instruction::get_type()
{
    int type[2];
    
    type[0] = instruction[0];
    type[1] = instruction[1];
    
    if ( type[0] == 0 && type[1] == 0)
        r_type = true;
    else if ( type[0] == 0 && type[1] == 1)
        i_type = true;
    else if ( type[0] == 1 && type[1] == 0)
        j_type = true;
    else if ( type[0] == 1 && type[1] == 1)
        p_type = true;
}

void Instruction::print_type()
{
    if ( r_type )
        cout << "this is a r type instruction\n";
    else if ( i_type )
       cout << "this is a i type instruction\n";
    else if ( j_type )
        cout << "this is a j type instruction\n";
    else if ( p_type )
        cout << "this is a p type instruction\n";
}

void Instruction::r_type_fn()
{
    type = R_TYPE;
    {
        int tmp[4];
        for (int i = 0; i < 4; i++){
            tmp[i] = instruction[i+2];
        }
        opcode = stringToBinary(tmp,3);
    }
    
    {
        int tmp[5];
        for (int i = 0; i < 5; i++){
            tmp[i] = instruction[i+6];
        }
        dest = stringToBinary(tmp,4);
    }
    
    {
        int tmp[5];
        for (int i = 0; i < 5; i++){
            tmp[i] = instruction[i+11];
        }
        src1 = stringToBinary(tmp,4);
    }
    
    {
        int tmp[5];
        for (int i = 0; i < 5; i++){
            tmp[i] = instruction[i+16];
        }
        src2 = stringToBinary(tmp,4);
    }
    
}

void Instruction::i_type_fn()
{
    type = I_TYPE;
    {
        int tmp[4];
        for (int i = 0; i < 4; i++){
            tmp[i] = instruction[i+2];
        }
        int x = stringToBinary(tmp,3);
        
        switch (x) {
            case ADD :
                opcode = ADDI;
                break;
            case SUB :
                opcode = SUBI;
                break;
            case MUL :
                opcode = MULI;
                break;
            case DIV :
                opcode = DIVI;
                break;
            case MOD :
                opcode = MODI;
                break;

            default:
                opcode = x;
                break;
        }
    }
    
    {
        int tmp[5];
        for (int i = 0; i < 5; i++){
            tmp[i] = (int) instruction[i+6];
        }
        dest = stringToBinary(tmp,4);
    }
    
    {
        int tmp[5];
        for (int i = 0; i < 5; i++){
            tmp[i] = (int) instruction[i+11];
        }
        src1 = stringToBinary(tmp,4);
        src2 = -1;
    }
    
    {
        int tmp[16];
        for (int i = 0; i < 16; i++){
            tmp[i] = (int) instruction[i+16];
        }
        immediate = stringToBinary(tmp,15);
    }
}

void Instruction::j_type_fn(){
    type = J_TYPE;
    {
        int tmp[29];
        for (int i = 0; i < 30; i++){
            tmp[i] = (int) instruction[i+2];
        }
        immediate = stringToBinary(tmp,29);
    }
}

int Instruction::get_type_(){
    return type;
}

void Instruction::p_type_fn()
{
    type = P_TYPE;
    src1 = -1;
    src2 = -1;
    
    opcode = 14;
    
    dest = 2;
    
    string str;
    cout << "Enter parameter: ";
    cin >> str;
    
    //check if value is integer
    for (int i = 0; i < str.size(); i++){
        while (!isdigit(str[i])) {
            cout << "Enter parameter: ";
            cin >> str;
        }
    }
    immediate = stoi(str);
}
