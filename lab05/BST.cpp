#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
  root = NULL;
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  DestroyBranch(root);
  root = NULL;
}

void BST::Insert(int toInsert) {
  if(root == NULL){
    root = new Node;
    root->val = toInsert;
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
  }else{
    InsertNode(toInsert,root);
  }
}
void BST::InsertNode(int toInsert, Node *node) {
  if(node->val > toInsert){
    if(node->left != NULL){
      InsertNode(toInsert,node->left);
    }else{
      node->left = new Node;
      node->left->val = toInsert;
      node->left->left = NULL;
      node->left->right = NULL;
      node->left->parent = node;
    }
  }else{
    if(node->right != NULL){
      InsertNode(toInsert,node->right);
    }else{
      node->right = new Node;
      node->right->val = toInsert;
      node->right->left = NULL;
      node->right->right = NULL;
      node->right->parent = node;
    }
  }
}
void BST::DestroyBranch(Node *node) {
  if(node != NULL){
    DestroyBranch(node->left);
    DestroyBranch(node->right);
//    if(node == node->parent->left)
//      node->parent->left = NULL;
//    if(node == node->parent->right)
//      node->parent->right = NULL;
    delete node;
  }
}
void BST::Delete(int toDelete) {
  Node* found = Search(toDelete);
  if(found->left == NULL)
    Transplant(found, found->right);
  else if(found->right == NULL)
    Transplant(found, found->left);
  else{
    Node* succ = Successor(found);
    if(succ->parent != found){
      Transplant(succ, succ->right);
      succ->right = found->right;
      succ->right->parent = succ;
    }
    Transplant(found, succ);
    succ->left = found->left;
    succ->left->parent = succ;
  }
  delete found;
}
void BST::Transplant(Node *u, Node *v) {
  if(u->parent == NULL)
    root = v;
  else if(u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  if(v != NULL)
    v->parent = u->parent;
}
Node *BST::Successor(Node *x) {
  if(x != NULL){
    if(x->right != NULL)
      return Minimum(x->right);  
    Node* y = x->parent;    
    while(y != NULL && x == y->right){
      x = y;
      y = y->parent;
    }
    return y;
 }
  return NULL;
}
Node *BST::Minimum(Node *x) {
  while(x->left != NULL)
    x = x->left;
  return x;
}
Node *BST::Maximum(Node *x) {
  while(x->right != NULL)
    x = x->right;
  return x;
}
Node *BST::Search(int toFind) {
  return SearchHelp(toFind, root);
}
Node *BST::SearchHelp(int toFind,Node *node) {
  if(toFind == node->val || node == NULL){
    return node;  
  }else if(toFind < node->val){
    SearchHelp(toFind,node->left);
  }else{
    SearchHelp(toFind,node->right);
  }
}
void BST::Print(TraversalOrder Order) {
  if(Order==InOrderTrav)
    InOrder(root);
  else if(Order==PreOrderTrav)
    PreOrder(root);
  else if(Order==PostOrderTrav)
    PostOrder(root);
}
void BST::PreOrder(Node *x) {
  if(x != NULL){
    cout<< x->val <<endl;
    PreOrder(x->left);
    PreOrder(x->right);
  }
}
void BST::InOrder(Node *x) {
  if(x != NULL){
    InOrder(x->left);
    cout<< x->val <<endl;
    InOrder(x->right);
  }
}
void BST::PostOrder(Node *x) {
  if(x != NULL){
    PostOrder(x->left);
    PostOrder(x->right);
    cout<< x->val <<endl;
  }
}
