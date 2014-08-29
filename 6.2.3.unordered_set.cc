#include "main.h"

#include <unordered_set>

void process ()
{
    unordered_set<double> coll;
    for (double i = 1; i < 7; ++i)
        coll.insert (1.0 / i);
    print (cout, coll);
}
