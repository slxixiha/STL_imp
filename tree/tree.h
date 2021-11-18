#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>

template <typename T>
struct TreeNode {
  T val;
  TreeNode* firstChild;
  TreeNode* nextSibling;
};

#endif



