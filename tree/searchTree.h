#include "tree.h"

#include <iostream>

// 非平衡
template<typename T >
class BinarySearchTree {
 public:
  BinarySearchTree() : root(nullptr) {};
  BinarySearchTree(const BinarySearchTree& rhs) {
    root = clone(rhs.root);
  }

  ~BinarySearchTree() {
    makeEmpty(root);
  }

  const T& findMin() const {
    SearchNode* minNode = findMin(root);
    return minNode->val;
  }

  const T& findMax() const {
    SearchNode* maxNode = findMax(root);
    return maxNode->val;
  }

  bool contains(const T& x) const {
    return contains(x, root);
  }

  bool isEmpty() const {
    return !root;
  }
  void printTree() const {
    printTree(root);
    std::cout << std::endl;
  }

  void makeEmpty() {
    return makeEmpty(root);
  }

  void insert(const T& x) {
    insert(x, root);
  }

  void remove(const T& x) {
    remove(x, root);
  }

  const BinarySearchTree& operator= (const BinarySearchTree& rhs) {
    if (this != rhs) {
      makeEmpty(root);
      root = clone(rhs.root);
      return *this;
    }
  }

  using SearchNode = BinaryNode<T>;

 private:

  SearchNode* root;
  
  // 注意重复元素的insert
  // 为了改变指针的内容，这里需要传递指针的引用
  void insert(const T& x, SearchNode*& t) const {
    if (!t) {
      t = new SearchNode;
      t->val = x;
      t->left = nullptr;
      t->right = nullptr;
      return;
    }

    // 先找到位置插入数据
    if (x < t->val) {
      insert(x, t->left);
    } else if (x > t->val) {
      insert(x, t->right);
    }

    // duplicate, do nothing
  }

  // 如果删除的次数不多，通常使用的策略是懒惰删除（标记删除）
  void remove(const T& x, SearchNode* t) {
    if (!t) return;

    // 找到要删除的节点
    if (x < t->val) {
      remove(x, t->left);
    } else if (x > t->val) {
      remove(x, t->right);
    }
  
    // 存在左右子树的时候使用右子树的最小值来作为新的根节点
    if (t->left && t->right) {
      // 节点的指向不用变，只需要更改节点的值
      //删除最小节点，最小节点一定只有右子树
      t->val = removeMin(t);
    } else {
      // 使用非空节点代替
      SearchNode* oldNode = t;
      if (!(t->left)) {
        t = t->right;
      } else {
        t = t->left;
      }

      delete oldNode;
    }
  }

  SearchNode* findMin(SearchNode* t) const {
    if (!t) return nullptr;

    if (!(t->left)) {
      return t;
    }
      
    return findMin(t->left);
  }
  
  T removeMin(SearchNode*& t) {
    // TODO: 为空抛异常？

    if (!(t->left)) {
      T tmp = t->val;
      delete t;
      t = nullptr;
      return tmp;
    }
  
    return removeMin(t->left);
  }

  SearchNode* findMax(SearchNode* t) const {
    if (!t) return nullptr;

    if(!(t->right)) {
      return t;
    }

    return findMax(t->right);
  }

  bool contains(const T& x, SearchNode* t) const {
    // 优先判断空树，保证t的有效性
    if (!t) return false;
  
    if (x < t->val) {
      return contains(x, t->right);
    } else if(x > t->val) {
      return contains(x, t->right);
    } else {
      // 最不可能的放最后
      return true;
    } 
  }

  void makeEmpty(SearchNode* t) {
    if (!t) return;

    if (t->left) {
      makeEmpty(t->left);
    }

    if (t->right) {
      makeEmpty(t->right);
    }

    delete t;
    t = nullptr;
  }
  
  void printTree(SearchNode* t) const {
    // 先序遍历，打印出来就是从小打到的数列
    if (!t) {
      return;
    }

    printTree(t->left);
    std::cout << t->val << " ";
    printTree(t->right);
  }

  SearchNode* clone(SearchNode* t) const {
    if (!t) return nullptr;

    return new SearchNode{t->val, clone(t->left), clone(t->right)};
  }
}; 

