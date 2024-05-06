#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the tree and
H is the height/depth of the tree
*/

#include <climits>

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int n)
{
    if (root == NULL)
    {
        return root;
    }

    bool flag = false;

    TreeNode<int> *nextLarger = NULL;

    if (root->data > n)
    {
        flag = true;
        nextLarger = root;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = getNextLargerElement(root->children[i], n);

        if (nextLarger == NULL)
        {
            nextLarger = temp;
        }
        else if (temp != NULL && temp->data < nextLarger->data)
        {
            flag = true;
            nextLarger = temp;
        }
    }

    return nextLarger;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int> *ans = getNextLargerElement(root, x);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}