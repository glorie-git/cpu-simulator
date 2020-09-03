//
//  Memory.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Memory.hpp"

Memory::Memory(){
    num_instrs = 0;
}

void Memory::read_file(string fname)
// Postcondition: a valid directory should be passed as a string
// String should be a path to a csv file
// ****
{
    file_name = fname;
    ifstream csv_fl;
    csv_fl.open(fname);
    string str;
  
    if (!csv_fl.is_open()) // if file is not found, print statement
    {
        cout << "could not open file" << endl;
    }
    else
    {
        //int i = 0;
        while (!csv_fl.eof())
        {
            getline(csv_fl, str, ',');
            instruction_memory.push_back(static_cast<unsigned int>(stoul(str)));
            num_instrs++;
            //i++;
        }
    }
    csv_fl.close(); // close file
}

int Memory::get_num_instrs(){
    return num_instrs;
}

unsigned int Memory::get_instr(int x){
    return instruction_memory[x];
}

int Memory::size(){
    return instruction_memory.size();
}

void Memory::reset(){
    instruction_memory.clear();
    num_instrs = 0;
}

void Memory::read_file()
// Postcondition: a valid directory should be passed as a string
// String should be a path to a csv file
// ****
{
    ifstream csv_fl;
    csv_fl.open(file_name);
    string str;
  
    if (!csv_fl.is_open()) // if file is not found, print statement
    {
        cout << "could not open file" << endl;
    }
    else
    {
        while (!csv_fl.eof())
        {
            getline(csv_fl, str, ',');
            instruction_memory.push_back(static_cast<unsigned int>(stoul(str)));
        }
    }
    csv_fl.close(); // close file
}
