#include<iostream>
#include<queue>
using namespace std;
#include "treeNode.h"
#include "take_input_level_wise.h"
#include "print_level_wise.cpp"

int countNodes(treeNode<int>* root){
    int sum=1;
    for(int i=0;i<root->children.size();i++){
        sum+=countNodes(root->children[i]);
    }
    return sum;
}

int main(){

    return 0;
}