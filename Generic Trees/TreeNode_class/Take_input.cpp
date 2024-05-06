#include<iostream>
#include<queue>
using namespace std;
#include "treeNode.h"
#include "take_input_level_wise.h"

treeNode<int>* takeInput(){
    int rootData;
    cout<<"enter the data "<<endl;
    cin>>rootData;
    treeNode<int>* root=new treeNode<int>(rootData);

    int n;
    cout<<"enter the number of children you want "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode<int>* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}

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

void printTree(treeNode<int>* root){
    if(root==NULL){ // egde case
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<"  ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    treeNode<int>* root=takeInputLevelWise();

    // treeNode<int>* root=takeInput();

    printLevelWise(root);
    return 0;
}