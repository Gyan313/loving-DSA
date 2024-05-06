#include<iostream>
#include<vector>
using namespace std;
#include "BinaryTree_Node_class.h"
#include "take_input_levelwise.cpp"
#include "print_levelwise.cpp"

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int> rightAns=heightDiameter(root->right);
    int lh=leftAns.first;
    int Rh=rightAns.first;
    int lD=leftAns.second;
    int RD=rightAns.second;

    int height=1+max(lh,Rh);
    int diameter=max(lh+Rh,max(lD,RD));
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}

// 1 -1 2 -1 3 -1 4 -1 -1  --> this sequence represent the binary tree to input
int main(){
    BinaryTreeNode<int>* root=take_input_levelwise();
    print_levelwise(root);

    pair<int,int> p=heightDiameter(root);
    cout<<"height = "<<p.first<<endl;
    cout<<"diameter = "<<p.second;
    delete root;
    return 0;
}