#include "main.h"

#include <set>
#include <unordered_set>

void process ()
{
    set<string> s1;
    s1.insert ({ "apple", "banana", "carrot", "date", "elderberry" });
    print (cout, s1);
    unordered_set<string> s2;
    s2.insert ({ "apple", "banana", "carrot", "date", "elderberry" });
    print (cout, s2);
}
