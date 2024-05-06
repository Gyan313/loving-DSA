#include<iostream>
#include<vector>
using namespace std;
#include "BinaryTree_Node_class.h"
#include "print_levelwise.cpp"
#include "take_input_levelwise.cpp"

vector<int>* root_to_Node_Path(BinaryTreeNode<int>* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int>* output=new vector<int>();
        output->push_back(data);
        return output;
    }

    vector<int>* leftOutput=root_to_Node_Path(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput=root_to_Node_Path(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    return NULL;
}
// 1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 -1 -1 -1
// above line of num is a tree i have written it so that you donot have to give input of a tree again and again , copy it at the input tree time

int main(){
    BinaryTreeNode<int>* root=take_input_levelwise();
    print_levelwise(root);
    cout<<endl;

    vector<int>* output=root_to_Node_Path(root,8);

    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<" ";
    }
    return 0;
}