#include "main.h"

#include <deque>

void process ()
{
    deque<int> coll;
    for (int i = 0; i < 6; ++i)
        coll.push_front (i);
    print (cout, coll);
}
