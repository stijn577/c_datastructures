#include <stdlib.h>
#include <string.h>

#include "../Lib/cString.h"

cString new_cString(const char *data) {
  size_t len = strlen(data);

  char *owned_data = (char *)malloc(len * sizeof(char));
  strcpy_s(owned_data, len, data);

  cString str = {
      .ptr = owned_data,
      .len = len,
  };

  return str;
}
