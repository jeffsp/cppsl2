#include "main.h"

#include <list>

void process ()
{
    list<int> coll;
    for (int i = 0; i < 6; ++i)
        coll.push_back (i);
    for (const auto &i : { -1, -2, -3 })
        coll.insert (coll.begin (), i);
    print (cout, coll);
}
