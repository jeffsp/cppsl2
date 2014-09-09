#include "main.h"

void process ()
{
    auto f = [] () { return 41; };
    double x = f () / 3;
    clog << x << endl;
    auto g = [] () -> double { return 41; };
    double y = g () / 3;
    clog << y << endl;
}
