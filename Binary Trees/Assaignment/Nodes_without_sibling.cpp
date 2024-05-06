/*
Time complexity : O(N)
Space complexity : O(H)

where N is the number of nodes in the tree
and H is the height of the tree.

H is equal to log(N) for a balanced tree
*/

void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        cout << root->right->data << " ";
    }
    else if (root->left != NULL && root->right == NULL)
    {
        cout << root->left->data << " ";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}