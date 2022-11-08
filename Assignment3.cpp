#include "BST.h"
#include <iostream>
using namespace std;

void options(){
    // a list of options
    cout << "Please select an option in the list below to test:\n" << endl;
    cout << "1: Insert a node" << endl;
    cout << "2: Search for a value" << endl;
    cout << "3: Find the predecessor (existing value ONLY !!!)" << endl;
    cout << "4: Find the successor (existing value ONLY !!!)" << endl;
    cout << "5: Find the height of the tree" << endl;
    cout << "6: Find the total number of nodes in  the tree" << endl;
    cout << "7: Delete a node" << endl;
    cout << "8: Traverse inorder and display" << endl;
    cout << "9: Traverse preorder and display" << endl;
    cout << "10: Traverse postorder and display" << endl;
    cout << "11: Check if a tree is balanced" << endl;
    cout << "12: Destroy tree" << endl;
    cout << "0: Quit" << endl;
}

void userInterface(){

    //Initiation of needed storage variables
    int userInput = 100;
    int nodeVal;
    int search_target_num;
    int delete_the_node;
    int predecessor_value;
    int successor_value;
    //design a mechanism to test your implementation continuously until user’s input is 0
    cout << "Welcome to BST program!";
    BST t;

    while (userInput != 0) {
        options();
        cout << "Enter chosen option: ";
        cin >> userInput;

        if (userInput == 1){
            // inserting a value;
            cout << "Insert Node: ";
            cin >> nodeVal;
            t.insertNode(nodeVal);
        }
        else if (userInput == 2){
            // Searching for a value
            cout << "What value do you want to find?: ";
            cin >> search_target_num;
            if(t.searchVal(search_target_num) == 1){
                cout << "Number " << search_target_num << " is in the Binary Tree" << endl;
            } else{
                cout << "Number " << search_target_num << " is not in the Binary Tree" << endl;
            }
        } else if (userInput == 3){
            //Find the predecessor of an existing value
            cout << "Input value that you want to find the predecessor of: ";
            cin >> predecessor_value;
            cout << t.findPredecessor(predecessor_value) << endl;
        } else if (userInput == 4){
            // Find the successor of an existing value
            cout << "Input value that you want to find the successor of: ";
            cin >> successor_value;
            cout << t.findSuccessor(successor_value) << endl;

        } else if (userInput == 5){
            // Find the height of the tree
            cout << "The height of the tree: ";
            cout << t.heightRes() << endl;
        } else if (userInput == 6){
            // Find the total number of nodes in tree
            cout << "The total number of nodes in the tree is: ";
            cout << t.totalNodes() << endl;
        } else if (userInput == 7){
            // Deleting a node
            cout << "What number would you like to delete?: ";
            cin >> delete_the_node;
            t.removeLeafNode(delete_the_node);
            cout << "The number" << " " << delete_the_node << " " << "has been deleted" << endl;
        } else if (userInput == 8){
            // Traverse inorder and display
            t.inorderDisplay();
            cout << endl;
        } else if (userInput == 9){
            // Traverse preorder and display
            t.preorderDisplay();
            cout << endl;
        } else if (userInput == 10){
            // Traverse postorder and display
            t.postorderDisplay();
        } else if (userInput == 11){
            // Check whether a tree is balanced
            cout << "Is Tree Balanced?: " << t.TreeBalance()<< endl;
        } else if (userInput == 12){
            // Destroying tree
            t.destroyTree();
            cout << "Tree has been destroyed"<< endl;
        }else{
            // checking before ending
            cout << endl;
            cout << "Is there anything else we wanted to do before we end   ?"<< endl;
            cout << "If we are done, enter 0 "<< endl;
            cout << "Enter option number: " ;
            cin >> userInput;
            cout <<endl;
        }

    }
    cout << "Thank you! See you next time !" <<endl;
 }



int main() {
    userInterface();
    return 0;
}


