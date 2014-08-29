#include "main.h"
#include <memory>
#include <vector>

void process ()
{
    shared_ptr<string> p1 (new string ("jeff"));
    shared_ptr<string> p2 (new string ("marissa"));
    {
        (*p1)[0] = 'J';
        (*p2)[0] = 'M';
        cout << "p1.use_count: " << p1.use_count () << endl;
        cout << "p2.use_count: " << p2.use_count () << endl;
        vector<shared_ptr<string>> ptrs { p1, p1, p2, p2, p2, p1, p2 };
        cout << "p1.use_count: " << p1.use_count () << endl;
        cout << "p2.use_count: " << p2.use_count () << endl;
        for (auto p : ptrs)
            cout << *p << endl;
        *p1 = "Drake";
        cout << "p1.use_count: " << p1.use_count () << endl;
        cout << "p2.use_count: " << p2.use_count () << endl;
        for (auto p : ptrs)
            cout << *p << endl;
    }
    cout << "p1.use_count: " << p1.use_count () << endl;
    cout << "p2.use_count: " << p2.use_count () << endl;
    // defining a deleter
    shared_ptr<string> p3 (new string ("blah"),
        [](string *p)
        {
            cout << "delete " << *p << endl;
            delete p;
        });
    vector<shared_ptr<string>> ptrs { p1, p2, p3, p3, p3, p3 };
    for (auto p : ptrs)
        cout << *p << endl;
    cout << "p1.use_count: " << p1.use_count () << endl;
    cout << "p2.use_count: " << p2.use_count () << endl;
    cout << "p3.use_count: " << p3.use_count () << endl;
}
