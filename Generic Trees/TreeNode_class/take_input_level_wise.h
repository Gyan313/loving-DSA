
treeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"enter the root node data "<<endl;
    cin>>rootData;
    treeNode<int>* root=new treeNode<int>(rootData);

    queue<treeNode<int>*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        treeNode<int>* front=nodes.front();
        nodes.pop();
        int n;
        cout<<"enter the number of children of "<<front->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"enter the child "<<i<<" data "<<endl;
            int childData;
            cin>>childData;
            treeNode<int>* child=new treeNode<int>(childData);
            front->children.push_back(child);
            nodes.push(child);
        }
    }
    return root;
}