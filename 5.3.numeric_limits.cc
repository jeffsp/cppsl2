#include "main.h"
#include <limits>

void process ()
{
    cout << "numeric_limits<int>::digits " << numeric_limits<int>::digits << endl;
    cout << "numeric_limits<short>::digits " << numeric_limits<short>::digits << endl;
    cout << "numeric_limits<long>::digits " << numeric_limits<long>::digits << endl;
    cout << "numeric_limits<long long>::digits " << numeric_limits<long long>::digits << endl;
    cout << "numeric_limits<float>::digits " << numeric_limits<float>::digits << endl;
    cout << "numeric_limits<float>::radix " << numeric_limits<float>::radix << endl;
    cout << "numeric_limits<float>::max_exponent " << numeric_limits<float>::max_exponent << endl;
    cout << "numeric_limits<double>::digits " << numeric_limits<double>::digits << endl;
    cout << "numeric_limits<double>::radix " << numeric_limits<double>::radix << endl;
    cout << "numeric_limits<double>::max_exponent " << numeric_limits<double>::max_exponent << endl;
    cout << "numeric_limits<long double>::digits " << numeric_limits<long double>::digits << endl;
    cout << "numeric_limits<long double>::radix " << numeric_limits<long double>::radix << endl;
    cout << "numeric_limits<long double>::max_exponent " << numeric_limits<long double>::max_exponent << endl;
}
