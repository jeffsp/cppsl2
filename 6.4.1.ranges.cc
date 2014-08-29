#include "main.h"

#include <algorithm>
#include <cassert>

void process ()
{
    vector<int> a = { 1, 2, 3, 4, 5, 6, 7 };
    auto pos = find (a.cbegin (), a.cend (), 10);
    assert (pos == a.end ());
    pos = find (a.cbegin (), a.cend (), 4);
    assert (pos != a.end ());
    cout << *pos << endl;
    cout << *max_element (a.cbegin (), a.cend ()) << endl;
}
