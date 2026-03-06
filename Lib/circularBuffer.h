#pragma once

typedef struct CircularBuffer {
  int *inner_buffer;
  size_t size;
  size_t index;
} CircularBuffer;

CircularBuffer new_CircularBuffer(size_t size);
void push_Data(CircularBuffer *buff, int data);

void print_CircularBuffer(CircularBuffer buff);

void free_CircularBuffer(void *buff);
