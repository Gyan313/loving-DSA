#include <climits>
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

void printLevelATNewLine(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++)
        {
            q.push(first->children[i]);
        }
    }
}

/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the tree and
H is the height/depth of the tree
*/

void replaceWithDepthValueHelper(TreeNode<int> *root, int depth)
{
    root->data = depth;

    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepthValueHelper(root->children[i], depth + 1);
    }
}

void replaceWithDepthValue(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    replaceWithDepthValueHelper(root, 0);
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}