#include "main.h"
#include <thread>
#include <future>

void func (promise<string> &p)
{
    try
    {
        string s ("hello there");
        p.set_value (move (s));
    }
    catch (...)
    {
        // set the promise's exception
        p.set_exception (current_exception ());
    }
}

void process ()
{
    promise<string> p;
    thread t (func, ref (p));
    t.detach ();

    // ...

    future<string> f (p.get_future ());
    cout << "result: " << f.get () << endl;
}
