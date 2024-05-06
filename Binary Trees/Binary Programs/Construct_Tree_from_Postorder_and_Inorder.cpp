/***********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
BinaryTreeNode<int>* helper(int *postorder, int *inorder,int postS,int postE,int inS,int inE){
	if(postS>postE || inS>inE){
		return NULL;
	}
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[postE]);
	int k=0;
	for(int i=inS;i<=inE;i++){
		if(root->data==inorder[i]){
			k=i;
			break;
		}
	}
	int LinS=inS;
	int LinE=k-1;
	int LpostS=postS;
    int LpostE=LinE-LinS+LpostS;
	int RinS=k+1;
	int RinE=inE;
	int RpostE=postE-1;
	int RpostS=RpostE-RinE+RinS;

	root->left=helper(postorder,inorder,LpostS,LpostE, LinS, LinE);
	root->right=helper(postorder,inorder,RpostS,RpostE, RinS, RinE);
	return root;
}

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength) {
  // Write your code here
  return helper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}