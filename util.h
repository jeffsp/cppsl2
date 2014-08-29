#include <iostream>

namespace jsp
{

template<typename T>
void print (std::ostream &ofs, const T &a)
{
    for (const auto &i : a)
        ofs << " '" << i << "'";
    ofs << std::endl;
}

template<typename T>
void print_pairs (std::ostream &ofs, const T &a)
{
    for (const auto &i : a)
        ofs << " '" << i.first << ',' << i.second << "'";
    ofs << std::endl;
}

};
