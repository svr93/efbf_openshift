#define BUILDING_NODE_EXTENSION

#include "factorize.h"

Handle<Value> factorize(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of args")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsNumber()) {

    ThrowException(Exception::TypeError(String::New("Wrong args")));
    return scope.Close(Undefined());
  }

  base n = args[0]->NumberValue();
    
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

  return scope.Close(Undefined()); // temporary
}
