#ifndef _FACTORIZATION_H_
#define _FACTORIZATION_H_

#include <iostream>
#include <algorithm> // for std::upper_bound
#include <map>
#include <vector>

using std::cout;
using std::map;
using std::vector;

typedef long long base;

/* ----- factorize ----- */

template <typename T, typename T2>
vector<vector<base> >
factorize (const T& n, map<T, unsigned>& result, T2 unused);

template
vector<vector<base> >
factorize <base, base> (const base& n, map<base, unsigned>& result, base unused);

/* ----- /factorize ----- */

#endif
