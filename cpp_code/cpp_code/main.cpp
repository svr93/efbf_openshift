#include <iostream>
#include <map>
#include <vector>

#include "factorization.h"

using std::cin;
using std::cout;
using std::endl;

using std::map;
using std::vector;

int main() {
  base n = 0;
  cin >> n;

  map <base, unsigned> m;
  vector<vector<base> >methods; // need replace base-->unsigned

  methods = factorize (n, m, (base) 0);

  for (vector<vector<base> >::iterator i = methods.begin();
       i != methods.end();
       ++i) {

    for (vector<base>::iterator j = (*i).begin();
         j != (*i).end();
         ++j) {

      cout << (*j) << ';';
    }

    cout << endl;
  }

  cout << "___" << endl;

  for (map <base, unsigned>::iterator i = m.begin();
       i != m.end();
       ++i) {

    cout << i->first << ' ' << i->second << endl;
  }

  return 0;
}
