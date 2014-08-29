#include "main.h"

#include <algorithm>
#include <vector>

void process ()
{
    vector<int> s1 = { 1, 2, 9, 7, 70, 10, 100, 200, 300, 900 };
    random_shuffle (begin (s1), end (s1));
    print (cout, s1);
    auto mm = minmax_element (begin (s1), end (s1));
    cout << "min/max " << *mm.first << " " << *mm.second << endl;
}
