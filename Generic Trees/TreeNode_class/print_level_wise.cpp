#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void printLevelWise(TreeNode<int> *root) {
  // Write your code here
  if (root == NULL) {
    return;                    // edge case
  }
  
  queue<TreeNode<int>*> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    TreeNode<int> *front = nodes.front();
    cout << front->data << ":";
    nodes.pop();
    for (int i = 0; i < front->children.size(); i++) {
      nodes.push(front->children[i]);
     if(i==front->children.size()-1){
         cout<<front->children[i]->data;
     }
     else{
         cout<<front->children[i]->data<<",";
     }
    }
    cout << endl;
  }
}

TreeNode<int>* take_InputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = take_InputLevelWise();
    printLevelWise(root);
}