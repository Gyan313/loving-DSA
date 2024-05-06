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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

#include <climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL){
		pair<int,int> p;
		p.first=INT_MAX;
		p.second=-1;
		return p;
	}
	pair<int,int> leftAns=getMinAndMax(root->left);
	pair<int,int> rightAns=getMinAndMax(root->right);

	int Lmin=leftAns.first;
	int Rmin=rightAns.first;
	int Lmax=leftAns.second;
	int Rmax=rightAns.second;

	int Min=min(root->data,min(Lmin,Rmin));
	int Max=max(root->data,max(Lmax,Rmax));

    pair<int, int> p;
    p.first = Min;
    p.second = Max;
    return p;
}