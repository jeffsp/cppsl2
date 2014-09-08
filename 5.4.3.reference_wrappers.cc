#include "main.h"
#include <algorithm>
#include <functional>
#include <list>
#include <vector>

void process ()
{
    list<int> l { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<reference_wrapper<int>> r (l.begin (), l.end ());
    cout << "original l:" << endl;
    for (auto i : l)
        cout << ' ' << i;
    cout << endl;
    cout << "r:" << endl;
    for (auto i : r)
        cout << ' ' << i;
    cout << endl;
    random_shuffle (begin (r), end (r));
    cout << "r:" << endl;
    for (auto i : r)
        cout << ' ' << i;
    cout << endl;
    for (auto &i : l)
        i = i * i;
    cout << "original l:" << endl;
    for (auto i : l)
        cout << ' ' << i;
    cout << endl;
    cout << "r:" << endl;
    for (auto i : r)
        cout << ' ' << i;
    cout << endl;
}
