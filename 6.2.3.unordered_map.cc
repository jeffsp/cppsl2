#include "main.h"

#include <unordered_map>

void process ()
{
    unordered_map<string,double> coll = {
        {"one_over_one", 1.0/1.0},
        {"one_over_two", 1.0/2.0},
        {"one_over_three", 1.0/3.0},
        {"one_over_four", 1.0/4.0}
        };
    print_pairs (cout, coll);
}
