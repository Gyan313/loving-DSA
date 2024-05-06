void printTree(treeNode<int>* root){
    if(root==NULL){ // egde case
        return;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}