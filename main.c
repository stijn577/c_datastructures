#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Lib/binaryTree.h"
#include "Lib/circularBuffer.h"
#include "Lib/linkedList.h"
// #include "Lib/structClass.h"

void run_LinkedList(void);
void run_BinaryTree(void);
void run_CircularBuffer(void);
void run_Herhaal(void);

typedef void (*defer_func_t)(void*);

typedef struct {
  defer_func_t func;
  void* arg;
  const char* func_name;
  const char* arg_name;
} defer_t;

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y) CONCATENATE_DETAIL(x, y)

// macro om een soort defered free te doen, zeker niet veilig voor een echte toepassing
#define defer(func, arg) defer_t CONCATENATE(_defer_, __LINE__) __attribute__((cleanup(defer_invoke))) = {func, arg, STRINGIFY(func), STRINGIFY(arg)}

#define STRINGIFY(x) #x

void defer_invoke(defer_t* d) {
  if (d && d->func) {
    printf("Executing deferred function: %s(%s)\n", d->func_name, d->arg_name);
    d->func(d->arg);
  }
}

int main(void) {
  srand(time(NULL));

  run_LinkedList();
  printf("\n");
  run_BinaryTree();
  printf("\n");
  run_CircularBuffer();
  printf("\n");
  run_Herhaal();
}

void run_LinkedList(void) {
  m_LinkedList head = new_LinkedList(10);
  defer(free_LinkedList, &head);

  push_BackLList(&head, 1992);
  push_BackLList(&head, 432);
  push_BackLList(&head, 2);
  push_BackLList(&head, 3);

  print_LList(head);

  push_FrontLList(&head, 12);
  push_FrontLList(&head, 15);

  print_LList(head);

  reverse_LList(&head);

  print_LList(head);

  push_BackLList(&head, 432);
  push_BackLList(&head, 2);
  push_BackLList(&head, 3);

  print_LList(head);

  reverse_LList(&head);

  print_LList(head);

  free_LinkedList(&head);
}

void run_BinaryTree(void) {
  m_BSTree tree = new_BSTree(rand());

  insert_BSTreeNode(&tree, rand());
  insert_BSTreeNode(&tree, rand());
}

void run_CircularBuffer(void) {
  CircularBuffer buff1 = new_CircularBuffer(5);
  defer(free_CircularBuffer, &buff1);

  CircularBuffer buff2 = new_CircularBuffer(10);
  defer(free_CircularBuffer, &buff2);

  push_Data(&buff1, rand());
  push_Data(&buff1, rand());
  push_Data(&buff1, rand());
  push_Data(&buff1, rand());
  push_Data(&buff1, rand());

  push_Data(&buff2, rand());
  push_Data(&buff2, rand());
  push_Data(&buff2, rand());
  push_Data(&buff2, rand());
  push_Data(&buff2, rand());

  print_CircularBuffer(buff1);
  print_CircularBuffer(buff2);
}

char* herhaal(const char* s, size_t n) {
  size_t s_len = strlen(s);
  size_t out_len = s_len * n + 1;
  char* out = (char*)malloc(out_len);

  char* iter = out;
  size_t iter_len = out_len;

  while (n > 0) {
    strcpy(iter, s);
    iter += s_len;
    n--;
  }

  return out;
}

void run_Herhaal(void) {
  const char* test = "test";
  char* repeated = herhaal(test, 3);
  printf("%s", repeated);
}
