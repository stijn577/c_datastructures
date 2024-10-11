#include <cstdlib>
#include <string.h>

typedef struct cString {
  char *ptr;
  size_t len;
  size_t capacity;
} cString;

cString *new_cString(void);
cString *new_cString(const char *data);
