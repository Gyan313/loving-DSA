#include<iostream>
using namespace std;
#include "treeNode.h"

int main(){           
    treeNode<int>* root=new treeNode<int>(1);
    treeNode<int>* node1=new treeNode<int>(2);
    treeNode<int>* node2=new treeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    return 0;
}