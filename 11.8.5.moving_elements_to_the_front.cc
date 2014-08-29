#include "main.h"

#include <algorithm>
#include <cassert>
#include <vector>

int r () { return rand () % 100; }

struct value
{
    int n;
    static size_t creates;
    static size_t destroys;
    static size_t assigns;
    static size_t compares;
    value (int n = 0) : n (n) { ++creates; }
    value (const value &v) : n (v.n) { ++creates; }
    ~value () { ++destroys; }
    value &operator= (const value &other) { ++assigns; n = other.n; return *this; }
    bool operator< (const value &other) const { ++compares; return n < other.n; }
    bool operator== (const value &other) const { return n == other.n; }
    friend ostream &operator<< (ostream &s, const value &v) { s << v.n; return s; }
};

size_t value::creates;
size_t value::destroys;
size_t value::assigns;
size_t value::compares;

void init ()
{
    value::creates = 0;
    value::destroys = 0;
    value::assigns = 0;
    value::compares = 0;
}

void stats (ostream &s, const size_t sz)
{
    s << "creates \t" << value::creates << endl;
    s << "destroys \t" << value::destroys << endl;
    s << "assigns \t" << value::assigns << endl;
    s << "compares \t" << value::compares << endl;
    s << "creates/elem \t" << value::creates/sz << endl;
    s << "destroys/elem \t" << value::destroys/sz << endl;
    s << "assigns/elem \t" << value::assigns/sz << endl;
    s << "compares/elem \t" << value::compares/sz << endl;
}

template<typename T>
void merge_sort (T s1, T s2)
{
    size_t sz = s2 - s1;
    if (sz < 2)
        return;
    vector<typename T::value_type> c1 (s1, s1 + sz / 2);
    vector<typename T::value_type> c2 (s1 + sz / 2, s2);
    merge_sort (begin (c1), end (c1));
    merge_sort (begin (c2), end (c2));
    merge (begin (c1), end (c1), begin (c2), end (c2), s1);
}

void process ()
{
    vector<value> x (10000);
    generate (begin (x), end (x), r);
    vector<value> y (x);
    sort (begin (y), end (y));
    vector<value> z;
    //print (cout, x);
    init ();
    z = x;
    cout << "sort" << endl;
    sort (begin (z), end (z));
    stats (cout, z.size ());
    assert (y == z);
    init ();
    z = x;
    cout << "stable_sort" << endl;
    stable_sort (begin (z), end (z));
    stats (cout, z.size ());
    assert (y == z);
    init ();
    z = x;
    cout << "merge_sort" << endl;
    merge_sort (begin (z), end (z));
    stats (cout, z.size ());
    assert (y == z);
}
