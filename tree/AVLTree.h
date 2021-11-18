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
  void insert(T& x) {
    insert(x, root);
  }

  void remove(T& x) {
    remove(x, root);
  }

 private:
  int height(AVLNode* t) const {
    return (!t) ? 0 : t->height;
  }

  int getHeight(AVLNode* t) const {
    if (!t) {
      return 0;
    } else {
      return max(height(t->left), height(t->right)) + 1;
    }
  }

  int getBalanceFactor(AVLNode* t) const {
    if (!t) {
      return 0;
    }

    return getHeight(t->left) - getHeight(t->right);
  }

  void rotateWithLeftChild(AVLNode*& t) {
    AVLNode* tl = t->left;
    t->left = tl->right;
    tl->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    tl->height = max(height(tl->left), height(tl->right)) + 1;
    t = tl;
  }

  /* 单旋转
   *    B               B
   *  A   C       =>  A     D
   *        D             C   E
   *          E
   */
  void rotateWithRightChild(AVLNode*& t) {
    AVLNode* tr = t->right;
    t->right = tr->left;
    tr->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    tr->height = max(height(tr->left), height(tr->right)) + 1;
    t = tr;
  }

  /* 双旋转
   *        k3                k2
   *    k1      D   =>    k1      k3
   *  A   k2            A   B   C   D
   *    B   C             
   */
  void doubleWithLeftChild(AVLNode*& t) {
    rotateWithRightChild(t->left);
    rotateWithLeftChild(t);
  }

  void doubleWithRightChild(AVLNode*& t) {
    rotateWithLeftChild(t->right);
    rotateWithRightChild(t);
  }

  AVLNode* rebalance(AVLNode* root) {
    int factor = getBalanceFactor(root);
    if (factor > 1) {
      if (getBalanceFactor(t->left) > 0) {
        return ro
      } else {

      }
    } else if (factor < -1) {
      if (getBalanceFactor(t->right) > 0) {

      } else {

      }
    } else {
      return root;
    }
  }

  // Internal method to insert into a subtree
  // set the new root of the subtree
  void insert(T& x, AVLNode*& t) {
    if (t == nullptr) {
      t = new AVLNode(x, nullptr, nullptr);
    } else if (x < t->val) {
      insert(x, t->left);
      if (height(t->left) - height(t->right) == 2) {
        if (x < t->left->val) {
          rotateWithLeftChild(t);
        } else {
          doubleWithLeftChild(t);
        }
      } else if (x > t->val) {
        insert(x, t->right);
        if(height(t->right) - height(t->left) == 2) {
          if (t->right->val < x) {
            rotateWithRightChild(t);
          } else {
            doubleWithRightChild(t);
          }
        } else {
          // Dublicate, do nothing
        }
      }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
  }

  T removeMin(SearchNode*& t) {
    if (!(t->left)) {
      T tmp = t->val;
      if (t->right) {
        t->val = t->right->val;
        delete t->right;
        t->right = nullptr;
      } else {
        delete t;
        t = nullptr;
      }

      return tmp;
    }
  
    return removeMin(t->left);
  }

  void remove(T& x, AVLNode* t) {
    if (t == nullptr) {
      return;
    }

    if (x < t->val) {
      remove(x, t->left);
    } else if (x > t->val) {
      remove(x, t->right);
    } else {
      if (t->right) {
        t->val = removeMin(x, t->right);
        if (height(t->left) - height(t->right) == 2) {
          
        }
      } else {
        
      }

    }
  }

 private:
  AVLNode* root;
};

