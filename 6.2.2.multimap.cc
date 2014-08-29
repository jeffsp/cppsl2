#include "main.h"

#include <map>

void process ()
{
    multimap<int,string> coll = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {6, "six"},
    };

    coll.insert ({ 5, "five" });
    coll.insert ({ 5, "five" });
    coll.insert ({ 5, "five" });

    print_pairs (cout, coll);
}
