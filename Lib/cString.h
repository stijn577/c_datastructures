#pragma once

#include <stdlib.h>

typedef struct cString {
  char *ptr;
  size_t len;
} cString;

cString new_cString(const char *data);
