#include "../Lib/structClass.h"
#include <stdio.h>

void print_fn(Foo const *foo) { printf("%zu\n", foo->data); }

Foo new_Foo(size_t data) {
  Foo foo = {
      .data = data,
      .print = print_fn,
  };
  return foo;
}
