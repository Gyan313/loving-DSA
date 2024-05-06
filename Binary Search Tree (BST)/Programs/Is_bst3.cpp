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


bool isBST(BinaryTreeNode<int>* root,int min=INT_MIN , int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data >max){
        return false;
    }
    bool isLeftok=isBST(root->left,min,root->data-1);
    bool isRightok=isBST(root->right,root->data,max);
    return isLeftok && isRightok;
}


// 4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int>* root = takeInput();
    bool output=isBST(root);
    cout << (output ? "true" : "false");
}   