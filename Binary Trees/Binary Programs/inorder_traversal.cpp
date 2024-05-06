#include<iostream>
using namespace std;
#include "BinaryTree_Node_class.h"
#include "print_levelwise.cpp"
#include "take_input_levelwise.cpp"

void inorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// 1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
// above line of num is a tree i have written it so that you donot have to give      input of a tree again and again , copy it at the input tree time

int main(){
    BinaryTreeNode<int>* root=take_input_levelwise();
    // BinaryTreeNode<int>* root=take_Input();
    // print_binaryTree(root);
    print_levelwise(root);
    cout<<endl;
    inorder(root);
    return 0;
}