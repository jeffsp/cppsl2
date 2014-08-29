#include "main.h"

#include <chrono>

void process ()
{
    // 20 * 1 / 1 seconds
    chrono::duration<int> twentySeconds (20);
    // 0.25 * 60 / 1 seconds
    chrono::duration<double,ratio<60>> fifteenSeconds (0.25);
    // 10 * 1 / 1000 seconds
    chrono::duration<unsigned,ratio<1,1000>> tenMilliseconds (10);

    // chrono has typedefs available
    chrono::nanoseconds oneNanosecond (1);
    chrono::microseconds oneMicrosecond (1);
    chrono::milliseconds oneMillisecond (1);
    chrono::seconds oneSecond (1);
    chrono::minutes oneMinute (1);
    chrono::hours oneHour (1);

    // arithmetic operations
    chrono::milliseconds d1 = oneHour - oneMinute - oneSecond - oneMillisecond;
    chrono::nanoseconds d2 = oneMicrosecond - oneNanosecond;
    cout << "diff 1 " << d1.count () << "ms" << endl;
    cout << "diff 2 " << d2.count () << "ns" << endl;
}
