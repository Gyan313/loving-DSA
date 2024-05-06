#include<iostream>
using namespace std;
#include "BinaryTree_Node_class.h"
#include "print_levelwise.cpp"
#include "take_input_levelwise.cpp"

int count_nodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+count_nodes(root->left)+count_nodes(root->right);
    return ans;
}

// 1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
// above line of num is a tree i have written it so that you donot have to give      input of a tree again and again , copy it at the input tree time

int main(){
    BinaryTreeNode<int>* root=take_input_levelwise();
    // BinaryTreeNode<int>* root=take_Input();
    // print_binaryTree(root);
    print_levelwise(root);
    cout<<"Number of nodes the tress has = "<< count_nodes(root);
    return 0;
}