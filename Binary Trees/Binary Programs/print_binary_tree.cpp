#include<iostream>
using namespace std;
#include "BinaryTree_Node_class.h"
#include "print_levelwise.cpp"
#include "take_input_levelwise.cpp"
#include "take_input.cpp"

void print_binaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L:"<<root->left->data<<",";
    }
    else{
        cout<<"L:-1"<<",";
    }
    if(root->right!=NULL){
        cout<<"R:"<<root->right->data;
    }
    else{
        cout<<"R:-1";
    }
    cout<<endl;
    print_binaryTree(root->left);
    print_binaryTree(root->right);
}

// 1 2 4 8 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root=take_input_levelwise();
    // BinaryTreeNode<int>* root=take_Input();
    // print_binaryTree(root);
    print_levelwise(root);
    return 0;
}