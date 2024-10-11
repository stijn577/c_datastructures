#include <stdlib.h>

#include "../Lib/binaryTree.h"

m_BSTree new_BSTree(size_t data) {
  m_BSTree new = malloc(sizeof(BSTreeNode));
  new->data = data;
  new->parent = NULL;
  new->left = NULL;
  new->right = NULL;

  return new;
}

static void insert_left(m_BSTree *parent, m_BSTree new) {
  new->parent = *parent;
  (*parent)->left = new;
}

static void insert_right(m_BSTree *parent, m_BSTree new) {
  new->parent = *parent;
  (*parent)->right = new;
}

void insert_BSTreeNode(m_BSTree *tree, size_t data) {
  // create the new node that will be inserted
  m_BSTree new = new_BSTree(data);

  m_BSTree helper = *tree;

  while (helper != NULL) {
    if (data <= helper->data) {
      if (helper->left == NULL) {
        insert_left(&helper, new);
        return;
      } else {
        helper = helper->left;
      }
    } else {
      if (helper->right == NULL) {
        insert_right(&helper, new);
        return;
      } else {
        helper = helper->right;
      }
    }
  }
}
