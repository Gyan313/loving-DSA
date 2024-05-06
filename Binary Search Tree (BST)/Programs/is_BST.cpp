#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


class isBSTreturn{
    public:
       bool is_BST;
       int minimum;
       int maximum;
};

isBSTreturn isBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        isBSTreturn output;
        output.is_BST=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    isBSTreturn leftoutput=isBST(root->left);
    isBSTreturn rightoutput=isBST(root->right);
    int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
    int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    bool ans=root->data>leftoutput.maximum && root->data<rightoutput.minimum && leftoutput.is_BST && rightoutput.is_BST;
    isBSTreturn output;
    output.is_BST=ans;
    output.maximum=maximum;
    output.minimum=minimum;
    return output;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root = takeInput();
    isBSTreturn output=isBST(root);
    cout << (output.is_BST ? "true" : "false");
}   