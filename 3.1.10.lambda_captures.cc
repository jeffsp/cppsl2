#include "main.h"

void process ()
{
    int x = 1;
    int y;
    // x=1 when this is defined
    auto f = [x, &y] () { y = x; };

    // ... so x=1 here
    f ();
    clog << x << ' ' << y << endl;

    x = 2;

    // ... and x=1 here
    f ();
    clog << x << ' ' << y << endl;

    // x=2 when this is defined
    auto g = [x, &y] () { y = x; };
    g ();
    // ... so x=2 here
    clog << x << ' ' << y << endl;

    // ... but x still =1 here
    f ();
    clog << x << ' ' << y << endl;
}
