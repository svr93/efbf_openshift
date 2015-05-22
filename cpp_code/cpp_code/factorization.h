#ifndef _FACTORIZATION_H_
#define _FACTORIZATION_H_

#include <algorithm> // for std::upper_bound
#include <map>
#include <vector>

using std::map;
using std::vector;

typedef long long base;

/* ----- factorize ----- */

template <typename T, typename T2>
void factorize (const T& n, map<T, unsigned>& result, T2 unused);

template
void factorize <base, base> (const base& n, map<base, unsigned>& result, base unused);

/* ----- /factorize ----- */

#endif
