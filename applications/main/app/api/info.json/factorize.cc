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

  Local<Array>resultArr = Array::New();

  clearVector();
  methods = factorize (n, m, (base) 0);

  for (vector<vector<base> >::iterator i = methods.begin();
       i != methods.end();
       ++i) {

    Local<Array>resultArrRow = Array::New();

    for (vector<base>::iterator j = (*i).begin();
         j != (*i).end();
         ++j) {

      resultArrRow->Set(Number::New(j - (*i).begin()), Number::New(*j));
    }

    resultArr->Set(Number::New(i - methods.begin()), resultArrRow);
  }

  Local<Array>primeNumbersArr = Array::New();

  base k = 0; // ??

  for (map <base, unsigned>::iterator i = m.begin();
       i != m.end();
       ++i) {

    Local<Array>primeNumbersArrRow = Array::New();

    primeNumbersArrRow->Set(Number::New(0), Number::New(i->first));
    primeNumbersArrRow->Set(Number::New(1), Number::New(i->second));
    primeNumbersArr->Set(Number::New(k++), primeNumbersArrRow);
  }

  Local<Object> response = Object::New();
  response->Set(String::NewSymbol("methods"), resultArr);
  response->Set(String::NewSymbol("primeNumbers"), primeNumbersArr);

  return scope.Close(response);
}
