#include "../tree/searchTree.h"

#include <vector>

using namespace std;

int main(void) {

  BinarySearchTree<int> searchTree;

  if (searchTree.isEmpty()) {
    cout << "check empty search tree ok." << endl;
  }

  vector<int> datas{3, 5, 1, 8, 2};

  for (auto n : datas) {
    searchTree.insert(n);
  }

  if (searchTree.contains(5)) {
    cout << "find 5 in serach tree ok." << endl;
  }

  if (8 == searchTree.findMax()) {
    cout << "find max in search tree ok." << endl;
  }

  if (1 == searchTree.findMin()) {
    cout << "find min in search tree ok." << endl;
  }

  cout << "before delete, print tree:";
  searchTree.printTree();

  searchTree.remove(3);
  cout << "after remove 3, print tree:";
  searchTree.printTree();

#if 0
  // 没定找不到时怎么返回
  searchTree.remove(6);
  cout << "after remove invalid 6, print tree:";
  searchTree.printTree();
#endif

  BinarySearchTree<int> searchTree_bak = searchTree;
  cout << "print bak tree:";
  searchTree_bak.printTree();

  searchTree.makeEmpty();
  if (searchTree.isEmpty()) {
    cout << "check empty after make empty ok." << endl;
  }

  return 0;
}
