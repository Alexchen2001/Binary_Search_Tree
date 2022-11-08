//
// Created by Alex Chen on 10/24/22.
//
#include <iostream>
#include <vector>
#include <cmath>
#include "BST.h"
using namespace std;



// For this lab, you do not need to consider the situation when inserting the same values.
// Only insert different values when you test your program in the main function.

//Constructor
BST::BST() {
    root = nullptr;
}

//Inserting a node
BST::TreeNode* BST::insert(TreeNode * t, int x) {
    /*
     * If the node has not been stored with a value it will initiate the
     * value it inserted, otherwise continue find place for the inserted value
     *(done trhough comparison of value of node and insert value)
     *if the inserted value already existed, print out a statement and ocompletes process
     */
    if(t == nullptr){
        t = new BST::TreeNode();
        t->val = x;
    }else if (x < t->val){
        t->left = insert(t->left,x);
    } else if(x > t->val){
       t->right =  insert(t->right, x);
    }else if(x == t->val){
        cout << "This value already existed in the tree!"<< endl;
    }
    return t;
}

// a public function that accesses the private function
void BST::insertNode(int x){
    root = insert(root, x);
}

// Searches for targeted value
int BST::search(TreeNode * t, int x) {
    /*
     * Tries to find the user_input value by going through the
     * binary tree
     *returns 1 for value found
     *returns -1 if the value is not in the tree
     */
   if(t == nullptr){
        return -1;
    }

    if(t -> val == x ){
        return 1;
    }else if (x < t->val){
        return search(t->left,x);
    }else if(x > t->val){
        return search(t->right, x);
    }
    return -1;

}

// a public function that calls the private search function
int BST::searchVal(int num){
    return search(root,num);
}

// helper function that calls another helper function to
//create a vector of in ordered sequence of the binary tree
vector<int> BST:: orderSeq(TreeNode * t, int num){
    vector<int> InOrderSeq;
    inOrderHelper(t,InOrderSeq );
    return InOrderSeq;
}

// recursively calls itself to sort the values to inorder sequence
// and stores it in the vector
void BST::inOrderHelper(TreeNode * t,vector<int> &InorderSeq) {
    //Inorder traverse L - Root -right
    //base case ( when the node is null return)
    if (t == nullptr) {
        return;
    }
    inOrderHelper(t->left, InorderSeq);
    InorderSeq.push_back(t->val);
    inOrderHelper(t->right,InorderSeq);

}

// Iterates through the vector and find the value before
// the given value, used helper function to sort into inorder
// then results the predecessor
int BST::findPredecessor(int num){
    vector<int> seq = orderSeq(root, num);
    for (int i = 0; i < seq.size(); i++){
        if (num == seq[i]){
            if (i == 0){
                return -1;
            }
            return seq[i - 1];
        }
    }
    return -1;
}

// deleting a node of user's choice,
// it recursively calls itself until it hits null pointer
// and when it finds the value and the
// left and right side of the Node is null pointer,
// then it is confirmed that it is leaf node and
// it deletes the node.
BST::TreeNode* BST::deleteNode(TreeNode * t, int num){
    if (t == nullptr){
        return nullptr;
    }

    t -> left = deleteNode(t -> left, num);
    t -> right = deleteNode(t -> right, num);

    if (t -> val == num && t -> left == NULL && t -> right == NULL) {
        delete t;
        return nullptr;
    }
    return t;
}

// a public function that calls the private function delete Node
void BST::removeLeafNode(int num){
    root = deleteNode(root, num);
}

// Iterates through the vector and find the value after
// the given value, used helper function to sort into inorder
// then results the successor
int BST::findSuccessor(int num){
    std::vector<int> seq = orderSeq(root, num);
    for (int i = 0; i < seq.size(); i++){
        if (num == seq[i]){
            if (i == seq.size() - 1){
                return -1;
            }
            return seq[i + 1];
        }
    }
    return -1;
}

//recursively iterates through each subtree, and
// finds the largest side, where then it would represent
// the height of the binary tree.
int BST:: findHeight(TreeNode * t){
    if (t == nullptr){
        return -1;
    }
    int heightrightside = findHeight(t -> right);
    int heightleftside = findHeight(t-> left);

    if(heightrightside > heightleftside){
        return 1 + heightrightside;
    }else{
        return 1 + heightleftside;
    }
}

// A public fundtion that calls findHeight private function
int BST:: heightRes(){
    return findHeight(root);
}

// Total Nodes, recursively calls itself
// and adding up the nodes that is in its subtree
// until it is null pointer.
int BST:: numOfNodes(TreeNode * t){
    if (t == nullptr){
        return 0;
    }else{
        return 1 + numOfNodes(t->left)+ numOfNodes(t->right);
    }
}

// a public function that calls the private function to
// retrieve result of total node.
int BST:: totalNodes(){
    return numOfNodes(root);
}


// Inorder traverse, prints the inorder sequence
void BST::inorder(TreeNode * t) {
    //Inorder travsere L - Root -right
    //base case ( when the node is null return)
    if (t == nullptr) {
        return;
    }
    inorder(t->left);
    cout << t->val << " ";
    inorder(t->right);

}

// public function that calls the inorder private function
void BST::inorderDisplay(){
    inorder(root);
}

// preorder traverse, prints the preorder sequence
void BST::preorder(BST::TreeNode * t) {
    // Preorder traverse Root - L - R
    if (t == nullptr){
        return;
    }
    cout << t->val << " ";
    preorder(t->left);
    preorder(t->right);

}

//public function that calls the private function preorder
void BST::preorderDisplay(){
    preorder(root);
}

// Postorder traverse, prints out post porder
void BST::postorder(BST::TreeNode * t) {
    // Post order traverse L - R - Root
    if (t == nullptr){
        return;
    }
    postorder(t->left);
    postorder(t->right);
    cout << t->val << " ";
}

// public functions that calls postorder from private
void BST::postorderDisplay(){
    postorder(root);
}

// using heights of each tsubtree to
// check whether if it is balanced
// recursively calls checkbalance and findHeight
// to result whether if it satisfy condition o f
// a balanced tree
int BST::checkBalance(TreeNode * t){
    int leftHeight;
    int rightHeight;

    if (t == nullptr){
        return 1;
    }

    leftHeight = findHeight(t -> left);
    rightHeight = findHeight(t -> right);

    if ((checkBalance(t->left) == 1) && (checkBalance(t->right) == 1) && (abs(leftHeight - rightHeight) <= 1)){
        return 1;
    }
    return -1;
}

// a public function that calls on the private function
// of check Balance
int BST::TreeBalance(){
    return checkBalance(root);
}

// clears every node in the tree, and set it to null pointer,
// deleting the node will  help prevent and space and memory
// errors/ overflows.
void BST::breakTree(TreeNode * t) {
    if (t == nullptr){
        return;
    }

    breakTree(t -> left);
    breakTree(t -> right);
    delete t;
    t = nullptr;
}

// a public function that calls the breaktree function
// and destorys the tree and set the root to null pointer
BST::TreeNode* BST::destroyTree() {
    breakTree(root);
    root = nullptr;
    return nullptr;
}

