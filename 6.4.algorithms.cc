#include "main.h"

#include <algorithm>

void process ()
{
    vector<int> a = { 7, 6, 5, 4, 1, 2, 3 };
    print (cout, a);
    sort (a.begin (), a.end ());
    print (cout, a);
}
