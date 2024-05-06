
#include <queue>

void print_levelwise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> children;
    children.push(root);
    while (!children.empty())
    {
        BinaryTreeNode<int> *front = children.front();
        cout << front->data << ":";
        children.pop();
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            children.push(front->left);
        }
        else
        {
            cout << "L:-1"<< ",";
        }
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            children.push(front->right);
        }
        else
        {
            cout << "R:-1";
        }
        cout << endl;
    }
}