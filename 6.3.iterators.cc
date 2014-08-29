#include "main.h"

#include <list>

void process ()
{
    list<int> l = { 1, 2, 3, 4, 5 };
    for (list<int>::const_iterator i = l.begin (); i != l.end (); ++i)
        cout << ' ' << *i;
    cout << endl;
}
