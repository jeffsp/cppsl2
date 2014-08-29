#include "main.h"

#include <vector>

void process ()
{
    vector<bool> a (10);
    cout << a.size () << endl;
    a[0] = 1;
    a.back () = 1;
    print (cout, a);
    // can't take address of element in vector<bool>
    //char *p = static_cast<char *> (&a[0]);
    //*p = 0xff;
}
