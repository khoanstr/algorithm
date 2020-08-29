#ifndef ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
#define ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_

#include <iostream>

namespace data_structures {
namespace trees {

template <class T>
class BinaryTree;

template <class T>
std::ostream &operator<<(std::ostream &out, const BinaryTree<T> &tree);

template <class T>
class BinaryTree {
 public:
  class Node {
   private:
    T data_;
    Node *left_;
    Node *right_;
    friend class BinaryTree;

   public:
    explicit Node(const T &data) : data_(data), left_(NULL), right_(NULL) {}
  };

 public:
  BinaryTree();
  ~BinaryTree();
  int Size() const;
  bool IsEmpty() const;
  void Insert(const T &e);
  T Remove(const T &e);

  friend std::ostream &operator<<(std::ostream &out, const BinaryTree &tree) {
    if (tree.IsEmpty()) {
      out << "Empty tree" << std::endl;
    } else {
      out << "Preorder traversal: ";
      tree.PreOrder(tree.root_);
      out << std::endl;

      out << "Inorder traversal: ";
      tree.InOrder(tree.root_);
      out << std::endl;

      out << "Postorder traversal: ";
      tree.PostOrder(tree.root_);
      out << std::endl;

      out << "Levelorder traversal: ";
      tree.LevelOrder(tree.root_);
      out << std::endl;
    }
    return out;
  }

 private:
  Node *root_;
  int size_;

 private:
  // Depth First Traversals
  std::ostream &PreOrder(std::ostream &out, Node *node) const;
  std::ostream &InOrder(std::ostream &out, Node *node) const;
  std::ostream &PostOrder(std::ostream &out, Node *node) const;
  // Breath First Traversal
  std::ostream &LevelOrder(std::ostream &out) const;
  std::ostream &PrintLevel(std::ostream &out, Node *node, int level) const;
  int Height(Node *node) const;
};

template <class T>
BinaryTree<T>::BinaryTree() : root_(NULL), size_(0) {}

template <class T>
BinaryTree<T>::~BinaryTree() {
  delete root_;
}

template <class T>
int BinaryTree<T>::Size() const {
  return size_;
}

template <class T>
bool BinaryTree<T>::IsEmpty() const {
  return (size_ == 0);
}

template <class T>
void BinaryTree<T>::Insert(const T &e) {
  Node *node = new Node(e);
  if (IsEmpty()) {
    root_ = node;
  } else {
  }
  size_++;
}

template <class T>
T BinaryTree<T>::Remove(const T &e) {
  return e;
}

template <class T>
int BinaryTree<T>::Height(BinaryTree::Node *node) const {
  if (node == NULL)
    return 0;
  else
    return 1 + std::max(Height(node->left), Height(node->right));
}

template <class T>
std::ostream &BinaryTree<T>::PreOrder(std::ostream &out, BinaryTree::Node *node) const {
  if (node == NULL) return out;
  out << node->data_ << " ";
  PreOrder(node->left_);
  PreOrder(node->right_);
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::InOrder(std::ostream &out, BinaryTree::Node *node) const {
  if (node == NULL) return out;
  InOrder(node->left_);
  out << node->data_ << " ";
  InOrder(node->right_);
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::PostOrder(std::ostream &out, BinaryTree::Node *node) const {
  if (node == NULL) return out;
  PostOrder(node->left_);
  PostOrder(node->right_);
  out << node->data << " ";
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::LevelOrder(std::ostream &out) const {
  for (int i = 1; i <= Height(root_); i++) out << PrintLevel(root_, i);
  return out;
}

template <class T>
std::ostream &BinaryTree<T>::PrintLevel(std::ostream &out, BinaryTree::Node *node, int level) const {
  if (node == NULL) return out;
  if (level == 1) {
    out << node->data_ << " ";
    return out;
  }
  PrintLevel(node->left_, level - 1);
  PrintLevel(node->right_, level - 1);
  return out;
}

}  // namespace trees
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_TREES_BINARY_TREE_H_
