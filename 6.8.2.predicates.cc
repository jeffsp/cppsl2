#include "main.h"

#include <vector>
#include <algorithm>

// predicates return bool
bool is_prime (unsigned n)
{
    if (n == 0 || n == 1)
        return false;
    int d;
    for (d = n / 2; n % d != 0; --d)
        ;
    return d ==1;
}

void process ()
{
    vector<int> a;
    for (auto i = 0; i < 30; ++i)
        a.push_back (i);
    vector<int> p;
    copy_if (a.cbegin (), a.cend (), back_inserter (p), is_prime);
    print (cout, p);
}
