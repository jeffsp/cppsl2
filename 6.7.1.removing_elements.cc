#include "main.h"

#include <algorithm>
#include <list>

void process ()
{
    list<int> s = { 5, 3, 1, 2, 3, 4, 3, 5, 6, 7, 8, 9, 3 };
    print (cout, s);
    auto new_end = remove (s.begin (), s.end (), 5);
    print (cout, s);
    // this is OK
    s.erase (new_end, s.end ());
    print (cout, s);
    // this is better
    s.remove (3);
    print (cout, s);
}
