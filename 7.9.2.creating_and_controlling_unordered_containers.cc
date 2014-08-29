#include "main.h"

#include <unordered_map>
#include <unordered_set>
#include <string>

struct A
{
    A (const A &b)
        : name (b.name)
        , age (b.age)
    { }
    A (const string &name, unsigned char age)
        : name (name), age (age)
    { }
    bool operator== (const A &b) const
    {
        return name == b.name && age == b.age;
    }
    string name;
    unsigned age;
    friend std::ostream& operator<< (std::ostream &s, const A &a)
    {
        s << a.name << ',' << a.age;
        return s;
    }
};

struct hash_A
{
    size_t operator() (const A &a) const
    {
        return a.age;
    }
};

typedef unordered_map<A,string,hash_A> grades;

template<typename T>
void print_hash_stats (ostream &s, const T &h)
{
    s << "bucket_count,load_factor,max_load_factor ";
    s << h.bucket_count ();
    s << "," << h.load_factor ();
    s << "," << h.max_load_factor () << endl;
}

void process ()
{
    grades p;
    p[A ("Joe", 20)] = "A";
    p[A ("Bill", 30)] = "A+";
    p[A ("Joe", 50)] = "F";
    print_pairs (cout, p);

    unordered_set<int> s = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print_hash_stats (cout, s);
    s.max_load_factor (0.5);
    print_hash_stats (cout, s);
    s.rehash (50);
    print_hash_stats (cout, s);
    unordered_set<int> t (100);
    print_hash_stats (cout, t);
    t.insert (s.begin (), s.end ());
}
