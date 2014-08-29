#include "main.h"

#include <algorithm>
#include <vector>

int RandModF (int n) { return rand () % n; }

struct RandModFO
{
    int operator() (int n)
    {
        return rand () % n;
    }
};

struct RandWithoutReplacement
{
    vector<int> r;
    size_t calls;
    RandWithoutReplacement (int max)
        : r (max)
        , calls (0)
    {
        for (size_t i = 0; i < r.size (); ++i)
            r[i] = i;
        random_shuffle (r.begin (), r.end ());
    }
    int operator() ()
    {
        if (calls >= r.size ())
            return -1;
        return r[calls++];
    }
};

void process ()
{
    vector<int> a = { 10, 20, 30, 40, 50, 60, 70 };
    print (cout, a);
    vector<int> b;
    // pass a function
    transform (a.cbegin (), a.cend (), back_inserter (b), RandModF);
    print (cout, b);
    vector<int> c;
    // pass a function object
    transform (a.cbegin (), a.cend (), back_inserter (c), RandModFO ());
    print (cout, c);
    // example with state
    vector<int> d (10);
    generate (d.begin (), d.end (), RandWithoutReplacement (d.size ()));
    print (cout, d);
}
