#include<iostream>
#include<queue>
using namespace std;
#include "treeNode.h"
#include "take_input_level_wise.h"
#include "print_level_wise.cpp"

void printAtLevelK(treeNode<int>* root,int k){
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}



int main(){
    treeNode<int>* root=takeInputLevelWise();
    cout<<endl;
    printAtLevelK(root,2);
    return 0;
}