//
//  Statistics.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Statistics.hpp"

Statistics::Statistics(){
    latency = 0.0;
    throughput = 0.0;
    clock = 0;
    total = 0;
    executed = 0;
}

void Statistics::set_total(int x){
    total = x;
}

void Statistics::increment_clock(){
    clock += 1;
}

void Statistics::increment_executed(){
    executed += 1;
}

void Statistics::print_stats(){
    cout << "Average latency per instruction: ";
    cout << get_latency() << endl;
    cout << "Average throughput per instruction: ";
    cout << get_throughput() << endl;
}

int Statistics::get_total(){
    return total;
}

double Statistics::get_latency(){
    latency = clock/total;
    return latency;
}

void Statistics::reset(){
    latency = 0;
    throughput = 0;
    clock = 0;
    total = 0;
    executed = 0;
}

double Statistics::get_throughput(){
    throughput = clock/executed;
    return throughput;
}
