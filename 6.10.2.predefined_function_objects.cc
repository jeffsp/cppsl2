#include "main.h"

#include <algorithm>
#include <functional>
#include <set>
#include <vector>

void process ()
{
    // as template parameter
    set<int,greater<int>> a = { 1, 2, 3, 4, 5, 6, 7 };
    print (cout, a);
    // as algorithm parameter
    vector<int> b (a.begin (), a.end ());
    sort (b.begin (), b.end (), less<int> ());
    print (cout, b);
}
