/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the input tree
and H is the height of the input tree
*/

int getSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);

    return leftSum + rightSum + root->data;
}