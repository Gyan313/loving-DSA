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
#include<math.h>
#include<vector>

vector<int>* arr(BinaryTreeNode<int> *root){
	if(root==NULL){
		return NULL;
	}
	vector<int>* lv=arr(root->left);
	vector<int>* rv=arr(root->right);
	vector<int>* newV=new vector<int>();
	newV.push_back(root->data);
	return newV;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	 if(root==NULL){
		 return;
	 }
	 vector<int> arr;
}