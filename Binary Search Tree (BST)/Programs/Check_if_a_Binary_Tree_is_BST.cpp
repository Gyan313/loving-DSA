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
#include <climits>
int maxNode(BinaryTreeNode<int> *root){
	if(root==NULL){
		return INT_MIN;
	}
	return max(root->data,max(maxNode(root->left),maxNode(root->right)));
}

int minNode(BinaryTreeNode<int> *root){
	if(root==NULL){
		return INT_MAX;
	}
	return min(root->data,min(minNode(root->left),minNode(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
  // Write your code here
  if (root == NULL) {
    return true;
  }
  int leftMax=maxNode(root->left);
  int rightMin=minNode(root->right);
  bool output=(root->data>leftMax) && (root->data<rightMin) && isBST(root->left) && isBST(root->right);
  return output;
}