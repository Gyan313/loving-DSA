#include <iostream>
using namespace std;

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

#include<climits>
class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
   public:
    BST() { 
        // Implement the Constructor
        root==NULL;
    }
    ~BST() { 
        // Implement the Constructor
        delete root;
    }
    
	/*----------------- Public Functions of BST -----------------*/
    private:
        int minimum(BinaryTreeNode<int>* root){
            if(root==NULL){
                return INT_MAX;
            }
            return min(root->data,min(minimum(root->left),minimum(root->right)));
        }

        BinaryTreeNode<int>* remove(BinaryTreeNode<int>* root,int data){
            if( root==NULL){
                return NULL;
            }
            if(root->data>data){
                root->left=remove(root->left, data);
            }
            else if(root->data<data){
                root->right=remove(root->right,data);
            }
            else{
                if(root->left!=NULL && root->right!=NULL){
                    int d=minimum(root->right);
                    root=remove(root,d );
                    root->data=d;
                    return root;
                } 
                else if (root->left == NULL && root->right != NULL) {
                  return root->right;
                }
                else if(root->right==NULL && root->left!=NULL){
                    return root->left;
                }
                else{
                    return NULL;
                }
            }
            return root;
        }
        
    public:
    void remove(int data) { 
        // Implement the remove() function 
        root=remove(root, data);
    }
    private:
        void print(BinaryTreeNode<int>* root){
            if(root==NULL){
                return;
            }
            cout<<root->data<<":";
            if(root->left!=NULL){
                cout<<"L:"<<root->left->data<<",";
            }
            if(root->right!=NULL){
                cout<<"R:"<<root->right->data;
            }
            cout<<endl;
            print(root->left);
            print(root->right);
        }
    public:
    void print() { 
        // Implement the print() function
        print(root);
    }
    private:
        BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root,int data){
            if(root==NULL){
                BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
                return root;
            }
            if(root->data>=data){
                BinaryTreeNode<int>* leftchild=insert(root->left, data);
                root->left=leftchild;
            }
            else{
                BinaryTreeNode<int>* rightchild=insert(root->right, data);
                root->right=rightchild;
            }
            return root;
        }
    public:
    void insert(int data) { 
        // Implement the insert() function 
       root=insert(root,data);
    }
    private:
        bool search(int data, BinaryTreeNode<int>* node){
            if(node==NULL){
                return false;
            }
            if(node->data==data){
                return true;
            }
            else if(node->data>data){
                return search(data,node->left);
            }
            else{
                return search(data,node->right);
            }
        }
    public:
    bool search(int data) {
		// Implement the search() function 
        return search(data,root);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}