#include "main.h"

#include <iterator>
#include <random>

const int N = 20;

template<typename T,typename U>
void stats (T &d, U &e)
{
    vector<typename T::result_type> v;
    for (int i = 0; i < N; ++i)
        v.push_back (d (e));
    cout << "mean " << accumulate (v.begin (), v.end (), typename T::result_type ()) * 1.0 / v.size ();
    cout << " : ";
    copy (v.begin (), v.end (), ostream_iterator<typename T::result_type> (cout, " "));
    cout << endl;
}

void process ()
{
    default_random_engine e;

    // uniform int
    uniform_int_distribution<int> uid (10, 13);
    stats (uid, e);

    // uniform real
    uniform_real_distribution<float> urd (10.0f, 13.0f);
    stats (urd, e);

    // bernoulli
    bernoulli_distribution bd (0.2);
    stats (bd, e);

    // binomial
    binomial_distribution<int> bid (40, 0.5);
    stats (bid, e);

    // poisson
    poisson_distribution<int> pd (10);
    stats (pd, e);

    // normal
    normal_distribution<float> nd (100.0f, 20.0f);
    stats (nd, e);
}
