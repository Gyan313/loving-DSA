/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the input tree
and H is the height of the input tree
*/

class BalancedReturnType
{
public:
    int height;
    bool balanced;
};

BalancedReturnType *isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        BalancedReturnType *ans = new BalancedReturnType();
        ans->height = 0;
        ans->balanced = true;
        return ans;
    }

    BalancedReturnType *ans1 = isBalancedHelper(root->left);
    BalancedReturnType *ans2 = isBalancedHelper(root->right);
    bool flag;

    if (!(ans1->balanced) || !(ans2->balanced) ||
        abs(ans1->height - ans2->height) > 1)
    {
        flag = false;
    }
    else
    {
        flag = true;
    }

    BalancedReturnType *output = new BalancedReturnType();
    output->height = max(ans1->height, ans2->height) + 1;
    output->balanced = flag;
    return output;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    return isBalancedHelper(root)->balanced;
}
