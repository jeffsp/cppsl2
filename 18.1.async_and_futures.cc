#include "main.h"
#include <chrono>
#include <future>
#include <thread>
#include <vector>

void sleep (size_t x)
{
    this_thread::sleep_for (chrono::milliseconds (x));
}

void func1 ()
{
    sleep (100);
    clog << '*';
}

void func2 ()
{
    sleep (200);
    clog << '+';
}

template<typename T>
void do_it (T pol)
{
    vector<future<void>> f;
    // do stuff in the future
    for (int i = 0; i < 10; ++i)
    {
        f.push_back (async (pol, func1));
        f.push_back (async (pol, func2));
    }
    // get results
    for (auto &i : f)
        i.get ();
    clog << endl;
}

void process ()
{
    // examples of using launch policies
    clog << "slow" << endl;
    do_it (launch::deferred);
    clog << "fast" << endl;
    do_it (launch::async);
}
