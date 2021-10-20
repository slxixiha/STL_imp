#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>

template <typename T>
struct TreeNode {
  T val;
  TreeNode* firstChild;
  TreeNode* nextSibling;
};

template <typename T>
struct BinaryNode {
  T val;
  BinaryNode* left;
  BinaryNode* right;
};


#endif



