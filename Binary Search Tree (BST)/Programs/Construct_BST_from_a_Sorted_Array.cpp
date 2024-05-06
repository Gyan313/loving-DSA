/**********************************************************

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

BinaryTreeNode<int>* constructBST(int *input, int s,int e){
	if(s>e){
		return NULL;
	}
	int mid=(s+e)/2;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(input[mid]);
	BinaryTreeNode<int>* leftchild=constructBST(input,s,mid-1);
	BinaryTreeNode<int>* rightchild=constructBST(input,mid+1,e);

	root->left=leftchild;
	root->right=rightchild;

	return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
	return constructBST(input,0,n-1);
}