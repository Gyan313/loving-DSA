/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	if(root==NULL){
		return NULL;
	}

	if(root->data==data){
		vector<int>* output=new vector<int>();
		output->push_back(root->data);
		return output;
	}
	else if(root->data>data){
        vector<int> *leftoutput =getPath(root->left, data);
		if(leftoutput!=NULL){
                  leftoutput->push_back(root->data);
        }
		return leftoutput;
    }
	else if(root->data<data){
        vector<int> *rightoutput =getPath(root->right, data);
		if(rightoutput!=NULL){

		rightoutput->push_back(root->data);
		}
		return rightoutput;
    }
}