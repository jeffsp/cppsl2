#include "main.h"

#include <set>

void process ()
{
    multiset<int> coll;
    for (int i = 0; i < 6; ++i)
        coll.insert (i);
    for (const auto &i : { -1, -2, -3 })
        coll.insert (i);
    for (int i = 0; i < 6; ++i)
        coll.insert (i);
    print (cout, coll);
}
