#include <iostream>
#include <queue>
#include <vector>
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


TreeNode<int>* takeInputLevelWise() {
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

TreeNode<int> *maxDataNode(TreeNode<int> *root) {
  // Write your code here

   // recursion 😢 implementation has not good time complexity --> NOT GOOD WAY
  /* 
  TreeNode<int>* max=root;
  for(int i=0;i<root->children.size();i++){
      if(max->data<maxDataNode(root->children[i])->data){
        max =maxDataNode(root->children[i]);
      }                                                                              
    }                                                                                   
  return max; 
  */

    // recursion ✌️ implementation has not good time complexity --> GOOD WAY   
  /* 
  TreeNode<int>* max=root;
  for(int i=0;i<root->children.size();i++){
      TreeNode<int>* node=maxDataNode(root->children[i]);
      if(max->data<node->data){
        max =node;
      }                                                                                
    }                                                                                      
  return max; 
*/

// queue❤️ implementation which less time consuming GOOD WAY
  queue<TreeNode<int> *> nodes;
  TreeNode<int> *max = root;
  nodes.push(root);
  while (!nodes.empty()) {
    TreeNode<int> *front = nodes.front();
    nodes.pop();
    for (int i = 0; i < front->children.size(); i++) {
      if (max->data <front->children[i]->data) {                         
        max = front->children[i];
      }
      nodes.push(front->children[i]);
    }
  }
  return max;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}