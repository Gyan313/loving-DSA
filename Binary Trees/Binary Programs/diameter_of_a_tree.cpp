#include<iostream>
#include<vector>
using namespace std;
#include "BinaryTree_Node_class.h"
#include "take_input_levelwise.cpp"
#include "print_levelwise.cpp"

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    // int L=height(root->left);
    // int R=height(root->right);
    // int ans=0;
    // if(L>R){
    //     ans=L+1;
    // }
    // else{
    //     ans=R+1;
    // }
    // return ans;

    return 1+max(height(root->left),height(root->right));
}

int heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    vector<int> pair;
    int h;
    int d;
}
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    int D1=height(root->left)+height(root->right);
    int D2=diameter(root->left);
    int D3=diameter(root->right);
    return max(D1,max(D2,D3));
}

// 1 -1 2 -1 3 -1 4 -1 -1
int main(){
    BinaryTreeNode<int>* root=take_input_levelwise();

    cout<<"h ="<<height(root)<<endl;
    cout<<"diameter = " <<diameter(root);
    return 0;
}