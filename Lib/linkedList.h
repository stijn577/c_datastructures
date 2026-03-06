#pragma once

typedef struct Node Node;
typedef struct Node {
  size_t data;
  Node *next;
} *m_LinkedList;
typedef Node const *c_List;

m_LinkedList new_LinkedList(size_t data);
void free_LinkedList(void *list);

void push_FrontLList(m_LinkedList *list, size_t data);
void push_BackLList(m_LinkedList *list, size_t data);

void reverse_LList(m_LinkedList *list);

void print_LList(c_List list);
void change_LList(m_LinkedList list);
