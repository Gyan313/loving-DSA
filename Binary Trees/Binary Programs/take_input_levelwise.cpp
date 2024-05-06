#include<queue>

BinaryTreeNode<int>* take_input_levelwise(){
    int rootData;
    cout<<"enter the root Data "<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cout<<"enter the left child data of "<<front->data<<endl;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftChild);
            front->left=child;
            pendingNodes.push(child);
        }

        int rightChild;
        cout<<"enter the right child data "<<front->data<<endl;
        cin>>rightChild;
        if(rightChild!=-1){
            BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightChild);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}