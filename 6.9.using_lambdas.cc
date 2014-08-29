#include "main.h"

#include <algorithm>
#include <vector>

void process ()
{
    vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> b;
    int m = 3;
    copy_if (a.cbegin (), a.cend (), back_inserter (b),
        [=] (int i) { return i % m == 0; });
    print (cout, a);
    cout << "multiples of " << m << endl;
    print (cout, b);
    sort (a.begin (), a.end (),
        [=] (int i, int j) { return i % m < j % m; });
    cout << "sorted by multiples of " << m << endl;
    print (cout, a);
}
