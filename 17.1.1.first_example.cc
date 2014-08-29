#include "main.h"
#include <algorithm>
#include <cassert>
#include <iterator>
#include <random>

struct gen
{
    uniform_int_distribution<int> d;
    default_random_engine e;
    gen (int min, int max) : d (min, max) { }
    int operator() ()
    {
        return d (e);
    }
};


void process ()
{
    // This example illustrates that the random number generator is deterministic.
    {
        const int N = 10;
        vector<int> a (N);
        vector<int> b (N);
        gen r1 (100, 200);
        gen r2 (100, 200);
        generate (a.begin (), a.end (), r1);
        generate (b.begin (), b.end (), r2);
        copy (a.begin (), a.end (), ostream_iterator<int> (cout, " "));
        copy (b.begin (), b.end (), ostream_iterator<int> (cout, " "));
        cout << endl;
        assert (a == b);
    }
    // You should always use a distribution rather than the output from the engine.
    {
        const int N = 50;
        default_random_engine e;
        for (int i = 0; i < N; ++i)
            cout << ' ' << e () % 2;
        cout << endl;
            uniform_int_distribution<int> d (0, 1);
        for (int i = 0; i < N; ++i)
            cout << ' ' << d (e);
        cout << endl;
    }
}
