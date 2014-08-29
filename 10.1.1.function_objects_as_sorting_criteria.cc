#include "main.h"

#include <set>
#include <sstream>

struct sort_crit
{
    bool operator() (const int &a, const int &b) const
    {
        stringstream sa;
        stringstream sb;
        sa << a;
        sb << b;
        return sa.str () < sb.str ();
    }
};

void process ()
{
    set<int> s1 = { 1, 2, 9, 7, 70, 10, 100, 200, 300, 900 };
    print (cout, s1);
    set<int,sort_crit> s2 (s1.begin (), s1.end ());
    print (cout, s2);
}
