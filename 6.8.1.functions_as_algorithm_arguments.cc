#include "main.h"

#include <algorithm>
#include <vector>

int square (int n)
{
    return n * n;
}

void process ()
{
    vector<int> x = { 1, 2, 3, 4, 5 };
    vector<int> y (x.size ());
    print (cout, x);
    print (cout, y);
    transform (x.begin (), x.end (), y.begin (), square);
    print (cout, y);
}
