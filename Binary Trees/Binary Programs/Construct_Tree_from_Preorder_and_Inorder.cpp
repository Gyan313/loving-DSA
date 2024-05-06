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
BinaryTreeNode<int>* newTree(int *preorder, int *inorder,int preS,int preE,int inS,int inE){
	if(preS>preE){
		return NULL;
	}
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[preS]);
	int n=0;
	// while(root->data!=inorder[i]){
	// 	i++;
	// 	n++;
	// }
	for(int i=inS;i<=inE;i++){
		if(root->data==inorder[i]){
			n=i;
			break;
		}
	}
	int LpreS=preS+1;
	int LinE=n-1;
	int LinS=inS;
	int LpreE=LpreS+LinE-LinS;
    root->left=newTree(preorder,inorder,LpreS,LpreE,LinS,LinE);

	int RpreS=LpreE+1;
	int RpreE=preE;
	int RinS=LinE+2;
	int RinE=inE;
	root->right=newTree(preorder,inorder,RpreS,RpreE,RinS,RinE);

	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	return newTree(preorder,inorder,0,preLength-1,0,inLength-1);
}