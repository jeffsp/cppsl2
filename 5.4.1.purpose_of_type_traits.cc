#include "main.h"
#include <complex>
#include <type_traits>

template<typename T>
void f_impl (T val, true_type)
{
    cout << "integral: " << val << endl;
}

template<typename T>
void f_impl (T val, false_type)
{
    cout << "not integral: " << val << endl;
}

template<typename T>
void f (T val)
{
    f_impl (val, is_integral<T> ());
}

namespace detail
{
    template<typename T> void f (T x);

    template<typename T>
    void f (T x, true_type)
    { cout << "integral " << x << endl; }

    template<typename T>
    void f (T x, false_type)
    { cout << "not integral " << x << endl; }
};

template<typename T>
struct A
{
    void f (T x)
    {
        detail::f (x, is_integral<T> ());
    }
};

void process ()
{
    f (12);
    f (1.2);
    f (complex<int> (1, 2));
    A<int> a1;
    A<float> a2;
    A<complex<int>> a3;
    a1.f (12);
    a2.f (1.2);
    a3.f (complex<int> (1, 2));
}
