#include "main.h"

#include <array>

void process ()
{
    array<int,6> coll;
    for (int i = 0; i < 6; ++i)
        coll[i] = i;
    print (cout, coll);
    // this won't work: array<int,5> tmp (coll);
    array<int,6> tmp (coll);
    print (cout, tmp);
}
