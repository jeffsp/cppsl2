#include "main.h"

#include <chrono>

template<typename C>
void print ()
{
    cout << "is_steady " << C::is_steady << endl;
    cout << "precision " << double (C::period::num) / C::period::den << endl;
    typedef typename ratio_multiply<typename C::period,kilo>::type TT;
    cout << "precision " << double (TT::num) / TT::den << endl;
}

void process ()
{
    // gcc has to be built with --enable-libstdcxx-time=rt for steady_clock, otherwise all the clocks types are the same
    print<chrono::system_clock> ();
    print<chrono::steady_clock> ();
    print<chrono::high_resolution_clock> ();
}
