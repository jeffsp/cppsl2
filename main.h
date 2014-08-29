/// @file main.h
/// @brief test boilerplate
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2014-06-06

#include "util.h"

#include <stdexcept>

using namespace std;
using namespace jsp;

void process ();

int main (int , char **)
{
    try
    {
        process ();

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what () << std::endl;
        return -1;
    }
}
