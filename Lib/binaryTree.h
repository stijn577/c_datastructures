#pragma once

#include <stddef.h>

typedef struct BSTreeNode BSTreeNode;
typedef struct BSTreeNode {
  size_t data;
  BSTreeNode *parent;
  BSTreeNode *left;
  BSTreeNode *right;
} *m_BSTree;
typedef BSTreeNode const *c_BSTree;

m_BSTree new_BSTree(size_t data);
void free_BSTree(void *head);

void insert_BSTreeNode(m_BSTree *tree, size_t data);

void print_BSTree(c_BSTree head);
