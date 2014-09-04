#include "main.h"
#include<ratio>

void process ()
{
    ratio<1,5> a;
    ratio<1*13,5*13> b;
    cout << a.num << "/" << a.den << "==" << b.num << "/" << b.den << endl;
    //ratio<13,0> c; // won't compile: divide by 0
    ratio_add<ratio<1,7>,ratio<22,26>> c;
    cout << c.num << "/" << c.den << endl;
}
