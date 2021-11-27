#include "../tree/AVLTree.h"

#include <vector>

using namespace std;

int main(void) {

  AVLTree<int> tree;

  if (tree.isEmpty()) {
    cout << "check empty AVL tree ok." << endl;
  }

  vector<int> datas{7, 6};
  for (auto n : datas) {
    tree.insert(n);
    cout << "after insert" << n << ":";
    tree.printTree();
  }

  tree.insert(1);
  cout << "after LL rotate, tree now:";
  tree.printTree();

  tree.insert(2);
  tree.insert(3);
  cout << "after RR rotate, tree now:";
  tree.printTree();

  tree.insert(4);
  cout << "after LR rotate, tree now:";
  tree.printTree();

  tree.remove(1);
  cout << "after remove 1, print tree:";
  tree.printTree();

  tree.insert(5);
  cout << "after RL rotate, tree now:";
  tree.printTree();

  tree.remove(6);
  cout << "after delete 6, tree now:";
  tree.printTree();

  tree.remove(3);
  cout << "aftrer delete 3, tree now:";
  tree.printTree();

  // 找不到时无操作
  tree.remove(3);
  cout << "after delete invalid 3, print tree:";
  tree.printTree();

  if (tree.contains(5)) {
    cout << "find 5 in serach tree ok." << endl;
  }

  if (7 == tree.findMax()) {
    cout << "find max in search tree ok." << endl;
  }

  if (2 == tree.findMin()) {
    cout << "find min in search tree ok." << endl;
  }

  AVLTree<int> tree_bak = tree;
  cout << "print bak tree:";
  tree_bak.printTree();

  tree.makeEmpty();
  if (tree.isEmpty()) {
    cout << "check empty after make empty ok." << endl;
  }

  return 0;
}