#include "main.h"

#include <algorithm>
#include <vector>

template<typename T>
struct mean
{
    mean () : sum (0), total (0) { }
    T sum;
    size_t total;
    T value () const { return sum / total; }
    void operator() (const T &x) { ++total; sum += x; }
};

void process ()
{
    vector<float> a = { 1.9, 2.8, 3.7, 4.6, 5.5 };
    mean<float> m = for_each (a.begin (), a.end (), mean<float> ());
    print (cout, a);
    cout << "mean " << m.value () << endl;
    // this seems more natural
    mean<float> m2;
    for (auto i : a)
        m2 (i);
    cout << "mean " << m2.value () << endl;
}
