#include "main.h"

#include<vector>

void process ()
{
    vector<int> a ({ 1, 2, 3, 4, 5, 6, 7 });
    print (cout, a);
    cout << "size " << a.size () << endl;
    cout << "capacity " << a.capacity () << endl;
    a.reserve (100);
    cout << "capacity " << a.capacity () << endl;
    a.shrink_to_fit ();
    cout << "capacity " << a.capacity () << endl;
}
