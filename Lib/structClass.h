#pragma once

typedef struct Foo {
  size_t data;
  void (*print)(struct Foo const *);
} Foo;

Foo new_Foo(size_t data);
