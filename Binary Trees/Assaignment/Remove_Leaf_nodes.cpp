/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the input tree
and H is the height of the input tree
*/

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return NULL;
    }

    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}