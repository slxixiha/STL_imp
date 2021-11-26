#include "../tree/AVLTree.h"

#include <vector>

using namespace std;

int main(void) {

  AVLTree<int> tree;

  if (tree.isEmpty()) {
    cout << "check empty AVL tree ok." << endl;
  }

  vector<int> datas{3, 2};
  for (auto n : datas) {
    tree.insert(n);
    cout << "after insert" << n << ":";
    tree.printTree();
  }

  tree.insert(1);
  cout << "after LL rotate, tree now:";
  tree.printTree();

#if 0
  if (tree.contains(5)) {
    cout << "find 5 in serach tree ok." << endl;
  }

  if (8 == tree.findMax()) {
    cout << "find max in search tree ok." << endl;
  }

  if (1 == tree.findMin()) {
    cout << "find min in search tree ok." << endl;
  }

  cout << "before delete, print tree:";
  tree.printTree();

  tree.remove(3);
  cout << "after remove 3, print tree:";
  tree.printTree();


  // 没定找不到时怎么返回
  tree.remove(6);
  cout << "after remove invalid 6, print tree:";
  tree.printTree();

  AVLTree<int> tree_bak = tree;
  cout << "print bak tree:";
  tree_bak.printTree();

  tree.makeEmpty();
  if (tree.isEmpty()) {
    cout << "check empty after make empty ok." << endl;
  }
#endif
  return 0;
}