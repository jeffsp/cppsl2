#include "main.h"

#include <vector>

void process ()
{
    vector<int> coll;
    for (int i = 0; i < 6; ++i)
        coll.push_back (i);
    print (cout, coll);
}
