#include "main.h"

#include <functional>
#include <unordered_map>

struct name
{
    string first;
    string last;
    name (const string &first, const string &last)
    : first (first), last (last) { }
    friend ostream &operator<< (ostream &s, const name &a)
    {
        s << a.first << " " << a.last;
        return s;
    }
    bool operator== (const name &a) const
    {
        return first == a.first && last == a.last;
    }
};

void process ()
{
    auto f = [] (const name &a)
    {
        hash<string> f;
        return f (a.first) + f (a.last);
    };
    unordered_map<name,size_t,decltype(f)> m (3, f);
    m[name ("ASDF", "XXX")] = 10;
    m[name ("QWER", "YYY")] = 20;
    m[name ("ZXCV", "ZZZ")] = 30;
    print_pairs (cout, m);
}
