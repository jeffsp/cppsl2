#include "main.h"
#include <chrono>
#include <future>
#include <thread>
#include <vector>

void sleep (size_t x)
{
    this_thread::sleep_for (chrono::milliseconds (x));
}

template<typename T>
void launch (T pol)
{
    vector<future<void>> f;
    // do stuff in the future
    for (int i = 0; i < 10; ++i)
    {
        f.push_back (async (pol, []{ sleep (100); clog << '*'; }));
        f.push_back (async (pol, []{ sleep (200); clog << '+'; }));
    }
    // get results
    for (auto &i : f)
        i.get ();
    clog << endl;
}

void wait ()
{
    // start a function now
    auto f = async (std::launch::async, []{ sleep (500); });
    // check it about 5 times
    int n = 0;
    while (f.wait_for (chrono::milliseconds (90)) != std::future_status::ready)
        clog << ' ' << ++n;
}

void process ()
{
    // examples of using launch policies
    clog << "slow" << endl;
    ::launch (std::launch::deferred);
    clog << "fast" << endl;
    ::launch (std::launch::async);
    clog << "waiting...";
    ::wait ();
    clog << " done" << endl;
}
