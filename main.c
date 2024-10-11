#include "Lib/binaryTree.h"
#include "Lib/linkedList.h"

void run_LinkedList(void);
void run_BinaryTree(void);

int main(void) {
  run_LinkedList();
  // run_BinaryTree();

  return 0;
}

void run_LinkedList(void) {
  m_LinkedList head = new_LinkedList(10);

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

  // free_LinkedList(&head);
}

void run_BinaryTree(void) {
  m_BSTree tree = new_BSTree(10);

  insert_BSTreeNode(&tree, 4);
  insert_BSTreeNode(&tree, 123);
}
