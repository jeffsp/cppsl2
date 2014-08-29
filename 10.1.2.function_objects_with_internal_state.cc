#include "main.h"

#include <algorithm>

struct A
{
    A (int n) : n (n) { }
    int operator() () { return n--; }
    int n;
};

void process ()
{
    vector<int> a (10);
    generate (a.begin (), a.end (), A (5));
    print (cout, a);
    vector<int> b;
    generate_n (back_inserter (b), 10, A (5));
    print (cout, b);
}
