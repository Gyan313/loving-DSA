#include<iostream>
#include<queue>
using namespace std;
#include "treeNode.h"
#include "take_input_level_wise.h"

void printLevelWise(treeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    queue<treeNode<int>*> nodes;
    
    while(!nodes.empty()){
        treeNode<int>* front=nodes.front();
        cout<<front->data<<":";
        nodes.pop();
        for(int i=0;i<front->children.size();i++){
            nodes.push(front->children[i]);
            cout<<front->children[i]->data<<",";
        }
        cout<<endl;
    }
}

void deleteTree(treeNode<int>* root){
    if(root==NULL){
        return;                         // one way of deleting the trees 
    }                                   
    for(int i=0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

// there is one other way which is more efficient and that is by the use of         destructor in treeNode class

// 1 3 2 3 4 2 5 6 2 7 8 1 9 0 0 0 0 0  this is our tree just copy it while checking your code works or not
int main(){
    treeNode<int>* root=takeInputLevelWise();

    // treeNode<int>* root=takeInput();

    printLevelWise(root);
    deleteTree(root);
    return 0;
}