//
//  Statistics.hpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#ifndef Statistics_hpp
#define Statistics_hpp

#include "HelperFunctions.hpp"

#endif /* Statistics_hpp */

class Statistics{
    
public:
    Statistics();
    void increment_clock();
    double get_latency();
    double get_throughput();
    void set_total(int);
    int get_total();
    void print_stats();
    void reset();
    void increment_executed();
    
private:
    double latency;
    double throughput;
    double clock;
    double total;
    double executed;
};
