#include <stdio.h>
#include <stdlib.h>

#include "../Lib/circularBuffer.h"

CircularBuffer new_CircularBuffer(size_t size) {
  int *arr = (int *)malloc(size * sizeof(int));
  CircularBuffer buffer = {
      .inner_buffer = arr,
      .size = size,
      .index = 0,
  };

  return buffer;
}

void push_Data(CircularBuffer *buff, int data) {
  buff->inner_buffer[buff->index] = data;
  buff->index = (buff->index + 1) % buff->size;
}

void print_CircularBuffer(CircularBuffer buff) {
  for (size_t iter = 0; iter < buff.size; iter++) {
    printf("%d\t", buff.inner_buffer[iter]);
  }
  printf("X\n");
}

void free_CircularBuffer(void *buff) {
  CircularBuffer *c_buff = (CircularBuffer *)buff;
  free(c_buff->inner_buffer);
}
