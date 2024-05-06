#include<queue>

BinaryTreeNode<int>* take_Input(){
    int rootData;
    cout<<"enter the data ";
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild=take_Input();
    BinaryTreeNode<int>* rightChild=take_Input();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}