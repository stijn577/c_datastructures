#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Lib/linkedList.h"

m_LinkedList new_LinkedList(size_t data) {
  printf("Creating new list with head value '%zu'...\n", data);
  m_LinkedList head = malloc(sizeof(Node));
  head->data = data;
  head->next = NULL;
  return head;
}

void push_FrontLList(m_LinkedList *list, size_t data) {
  m_LinkedList new = malloc(sizeof(Node));
  new->data = data;
  new->next = *list;

  // printf("Pushing '%zu' to front...\n", data);

  *list = new;
}

void push_BackLList(m_LinkedList *list, size_t data) {
  m_LinkedList new = malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;

  if (!list) {
    *list = new;
  }

  // printf("Pushing '%zu' to back...\n", data);

  m_LinkedList help = *list;
  while (help->next) {
    help = help->next;
  }

  help->next = new;
}

void reverse_LList(m_LinkedList *list) {
  printf("Reversing list...\n");

  m_LinkedList prev = *list;
  m_LinkedList curr = prev->next;

  // check if list is max one element long
  // if it is we don't need to do anything
  if (!prev || !curr) {
    return;
  }

  // set the first connection correctly, otherwise list would go back and forth
  // on second to last and third to last node also set the future
  // final_node->next to NULL so the list doesn't keep going
  m_LinkedList lookahead = prev->next->next;
  prev->next = NULL;
  curr->next = prev;
  prev = curr;

  // check if list is 2 elements long, if it is, we are done already
  // and we can return
  if (!lookahead) {
    return;
  }

  // loop logic that iteratively goes over the list and swaps the nodes
  // at any given start of the while loop the situation looks like this:
  // NULL <--- a <--- b      c ---> d ---> e ---> NULL
  //         ^prev    ^curr  ^ lookahead
  // this then becomes step by step:
  // prev = curr;
  // NULL <--- a <--- b      c ---> d ---> e ---> NULL
  //                  ^curr  ^ lookahead
  //                  ^prev
  // curr = lookahead;
  // NULL <--- a <--- b      c ---> d ---> e ---> NULL
  //                         ^ lookahead
  //                  ^prev  ^ curr
  // lookahead = lookahead->next;
  // NULL <--- a <--- b      c ---> d ---> e ---> NULL
  //                  ^prev  ^ curr ^lookahead
  // when the first three lines are done, we then change curr->next to point to
  // prev, reversing that part of the list
  // curr->next = prev
  // NULL <--- a <--- b <--- c      d ---> e ---> NULL
  //                  ^prev  ^ curr ^lookahead
  while (lookahead) {
    prev = curr;
    curr = lookahead;
    lookahead = lookahead->next;

    curr->next = prev;
  }

  *list = curr;
}

void print_LList(c_List list) {
  // printf("Printing list...\n");
  while (list) {
    printf("%zu\t", list->data);
    list = list->next;
  }
  printf("X\n");
}

void free_LinkedList(void *list) {
  m_LinkedList *_list = (m_LinkedList *)list;
  m_LinkedList help = *_list;
  while (*_list != NULL) {
    help = (*_list)->next;
    free(*_list);
    *_list = help;
  }

  list = NULL;
}
