#include <iostream>

template <typename T>
struct AVLNode {
  T val;
  AVLNode* left;
  AVLNode* right;
  int height;

  AVLNode(const T& v, AVLNode* l, AVLNode* r, int h = 0) : val(v), left(l), right(r), height(h) {}
};

template <typename T>
class AVLTree {
 public:
  using node = AVLNode<T>;

  AVLTree() : root(nullptr) {};
  AVLTree(const AVLTree& rhs) {
    root = clone(rhs.root);
  }
  const AVLTree& operator= (const AVLTree& rhs) {
    if (this != rhs) {
      makeEmpty(root);
      root = clone(rhs.root);
      return *this;
    }
  }

  ~AVLTree() {
    makeEmpty(root);
  }

  const T& findMin() const {
    node* minNode = findMin(root);
    return minNode->val;
  }

  const T& findMax() const {
    node* maxNode = findMax(root);
    return maxNode->val;
  }

  void insert(const T& x) {
    insert(x, root);
  }

  void remove(const T& x) {
    remove(x, root);
  }

  bool isEmpty() const {
    return !root;
  }

  void makeEmpty() {
    return makeEmpty(root);
  }

  bool contains(const T& x) const {
    return contains(x, root);
  }

  void printTree() const {
    printTree(root);
    std::cout << std::endl;
  }

 private:
  int height(node* t) const {
    return (!t) ? -1 : t->height;
  }

  int getBalanceFactor(const node* t) const {
    if (!t) {
      return 0;
    }

    return height(t->left) - height(t->right);
  }

  /* 单旋转      
   *      3      2
   *    2   => 1   3
   *  1        
   */
  // 右旋， LL型
  node* rotateWithLeftChild(node* t) {
    node* tl = t->left;
    t->left = tl->right;
    tl->right = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    tl->height = std::max(height(tl->left), height(tl->right)) + 1;
    return tl;
  }

  /* 单旋转
   *  3       =>    4
   *    4         3   5
   *      5
   */
  // 左旋， RR型
  node* rotateWithRightChild(node* t) {
    node* tr = t->right;
    t->right = tr->left;
    tr->left = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    tr->height = std::max(height(tr->left), height(tr->right)) + 1;
    return tr;
  }

  /* 双旋转
   *          5                 5            3   
   *    2       6   =>      3     6   =>   2     5
   *  1   3               2   4          1     4   6
   *        4           1    
   */
  // LR型
  node* doubleWithLeftChild(node* t) {
    t->left = rotateWithRightChild(t->left);
    return rotateWithLeftChild(t);
  }

  /* 双旋转
   *    3                 3                  4
   *  2       6         2   4              3     6
   *      4     7   =>          6     => 2     5   7
   *        5                 5   7
   */
  // RL型
  node* doubleWithRightChild(node* t) {
    t->right = rotateWithLeftChild(t->right);
    return rotateWithRightChild(t);
  }

  node* rebalance(node* t) {
    int factor = getBalanceFactor(t);
    if (factor > 1) {
      if (getBalanceFactor(t->left) > 0) {  // LL
        return rotateWithLeftChild(t);
      } else {  // LR
        return doubleWithLeftChild(t);
      }
    } else if (factor < -1) {
      if (getBalanceFactor(t->right) > 0) { // RL
        return doubleWithRightChild(t);
      } else {  // RR
        return rotateWithRightChild(t);
      }
    } else {
      t->height = std::max(height(t->left), height(t->right)) + 1;
      return t;
    }
  }

  // Internal method to insert into a subtree
  // set the new root of the subtree
  void insert(const T& x, node*& t) {
    if (!t) {
      t = new node(x, nullptr, nullptr, 0);
    }

    if (x == t->val) {
      return;
    } else if (x < t->val) {
      insert(x, t->left);
    } else {
      insert(x, t->right);
    }

    t = rebalance(t);
  }

  T removeMin(node*& t) {
    if (!(t->left)) {
      T tmp = t->val;
      if (t->right) {
        t->val = t->right->val;
        delete t->right;
        t->right = nullptr;
        t->height = 0;
      } else {
        delete t;
        t = nullptr;
      }

      return tmp;
    }
  
    return removeMin(t->left);
  }

  void remove(const T& x, node*& t) {
    if (t == nullptr) {
      return;
    }

    if (x < t->val) {
      remove(x, t->left);
    } else if (x > t->val) {
      remove(x, t->right);
    } else {
      if (t->right) {
        t->val = removeMin(t->right);
      } else if (t->left) {
        // 左子树只有单个节点
        t->val = t->left->val;
        delete t->left;
        t->left = nullptr;
        t->height = 0;
        return;
      } else {
        delete t;
        t = nullptr;
        return;
      }
    }
    t = rebalance(t);
  }

  bool contains(const T& x, node* t) const {
    // 优先判断空树，保证t的有效性
    if (!t) return false;
  
    if (x < t->val) {
      return contains(x, t->left);
    } else if(x > t->val) {
      return contains(x, t->right);
    } else {
      // 最不可能的放最后
      return true;
    } 
  }

  node* findMax(node* t) const {
    if (!t) return nullptr;

    if(!(t->right)) {
      return t;
    }

    return findMax(t->right);
  }

  node* findMin(node* t) const {
    if (!t) return nullptr;

    if (!(t->left)) {
      return t;
    }
      
    return findMin(t->left);
  }

  void printTree(node* t) const {
    // 先序遍历，打印出来就是从小打到的数列
    if (!t) {
      return;
    }

    printTree(t->left);
    std::cout << t->val << ":" << t->height << " ";
    printTree(t->right);
  }

  void makeEmpty(node*& t) {
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

  node* clone(node* t) const {
    if (!t) return nullptr;

    return new node{t->val, clone(t->left), clone(t->right), 0};
  }

 private:
  node* root;
};

