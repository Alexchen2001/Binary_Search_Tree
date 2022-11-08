//
// Created by Alex Chen on 10/24/22.
//

#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H

#include <vector>
#include <iostream>
using namespace std;



class BST {
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
// For this lab, you do not need to consider the situation when inserting the same values.
// Only insert different values when you test your program in the main function.

    TreeNode* insert(TreeNode * t, int x);
    int search(TreeNode* t, int x);
    int findHeight(TreeNode* t);
    vector<int> orderSeq(TreeNode * t, int num);
    int numOfNodes(TreeNode * t);
    void inOrderHelper(TreeNode * t, std::vector<int> &Inorderseq);
    TreeNode* deleteNode(TreeNode * t, int num);
    void inorder(TreeNode * t);
    void preorder(TreeNode * t);
    void postorder(TreeNode * t);
    int checkBalance(TreeNode * t);
    void breakTree(TreeNode * t);
public:
    BST();
    void insertNode(int x);
    void inorderDisplay();
    void preorderDisplay();
    void postorderDisplay();
    void removeLeafNode(int num);

    int heightRes();
    int TreeBalance();
    TreeNode* destroyTree();
    int searchVal(int num);
    int totalNodes();
    int findPredecessor(int x);
    int findSuccessor(int x);

};


#endif //ASSIGNMENT_3_BST_H
