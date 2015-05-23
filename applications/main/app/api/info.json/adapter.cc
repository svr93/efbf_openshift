#define BUILDING_NODE_EXTENSION

#include <node.h>

#include "factorize.h"

using namespace v8;

void Init(Handle<Object> exports) {

  exports->Set(String::NewSymbol("factorize"),
               FunctionTemplate::New(factorize)->
                 GetFunction());
}

NODE_MODULE(addon, Init)
