//
//  main.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Pipeline.hpp"

#include <iostream>

int main(int argc, const char * argv[]) {
    
    Pipeline program;
    char  str;
    bool is_you_done = false;
    string fname;
    string condition = "exit";
    bool debug;
    string entry;
    ifstream csv_fl;
    string str1;
    
    
    
    do {
        cout << "Type \"exit\" to terminate this application\n";
        cout << "Enter a program for execution: ";
        cin >> entry;
        cout << endl;
        if (entry.compare(condition) == 0)
            is_you_done = true;

        else {
            csv_fl.open(entry+".csv");
            if (csv_fl.is_open()) {
                csv_fl.close();
                do {
                    cout << "EXECUTION MODE (e) or DEBUG MODE (d) : ";
                    cin >> str;
                } while (str != 'e' && str != 'E' && str != 'd' && str != 'D');
                
                if ( str == 'd' || str == 'D')
                    debug = true;
                else
                    debug = false;
                
                cout << "reading file " << entry << ".csv\n\n";
                cout << endl;
            
            
                program.initiate_pipeline(entry+".csv");
                program.start(debug);
                program.print_stats();
                program.reset();
                fname = "";
                is_you_done = false;
                str = ' ';
                cout << endl;
                cout << endl;
            }
            else
                cout << "please try again...\n";
        }
        csv_fl.close();
    } while (!is_you_done);
    
    
    return 0;
}
