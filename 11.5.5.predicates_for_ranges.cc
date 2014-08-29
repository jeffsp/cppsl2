#include "main.h"

#include <algorithm>
#include <vector>

void process ()
{
    vector<int> a = { 1, 7, 5, 3, 9, 2, 8, 6, 2, 4 };
    vector<int> b = { 2, 4, 7, 8, 3, 6, 9, 12 };
    cout << "a ";
    print (cout, a);
    auto is_odd = [] (int x) { return x & 1; };
    auto is_multiple_of_3 = [] (int x) { return !(x % 3); };
    cout << "partitions" << endl;
    cout << "is_odd(a) : "
        << is_partitioned (begin (a), end (a), is_odd)
        << endl;
    cout << "is_multiple_of_3(a) : "
        << is_partitioned (begin (a), end (a), is_multiple_of_3)
        << endl;
    cout << "b ";
    print (cout, b);
    cout << "is_multiple_of_3(b) : "
        << is_partitioned (begin (b), end (b), is_multiple_of_3)
        << endl;
    cout << "is_multiple_of_3(reverse(b)) : "
        << is_partitioned (b.rbegin (), b.rend (), is_multiple_of_3)
        << endl;
}
