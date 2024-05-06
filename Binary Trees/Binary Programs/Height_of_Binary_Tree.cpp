// Your soln "bad"
int height(BinaryTreeNode<int>* root) {
    // Write our code here
	if(root==NULL){
		return 0;
	}
	int ans=0;
	int leftH=height(root->left);
	int rightH=height(root->right);
	if(leftH>rightH){
		ans=1+leftH;
	}
	else{
		ans=rightH+1;
	}
	return ans;
}

// coding ninjas soln

/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the input tree
and H is the height of the input tree
*/

int height(BinaryTreeNode<int> *root) {
if (root == NULL) {
return 0;
}

return max(height(root->left), height(root->right)) + 1;
}


/* 
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << height(root);
} 
*/