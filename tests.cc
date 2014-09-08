#include "main.h"

#include <algorithm>
#include <vector>

struct A
{
    float v;
    size_t n;
    A () : v (static_cast<double> (rand ()) / RAND_MAX) , n (0) { }
    bool operator< (const A &b) const
    {
        return v < b.v;
    }
    ostream &print (ostream &s) const
    {
        s << ' ' << v << ", " << n;
        return s;
    }
};

ostream &operator<< (ostream &s, const A &a)
{
    return a.print (s);
}

void process ()
{
    vector<A> p (10);
    for (size_t i = 0; i < p.size (); ++i)
        p[i].n = i;
    sort (p.begin (), p.end ());
    for (auto i : p)
        cout << i;
    cout << endl;
    vector<pair<float,size_t>> q (10);
    for (size_t i = 0; i < q.size (); ++i)
    {
        q[i].first = static_cast<double> (rand ()) / RAND_MAX;
        q[i].second = i;
    }
    sort (q.begin (), q.end ());
    for (auto i : q)
        cout << ' ' << i.first << ", " << i.second;
}
