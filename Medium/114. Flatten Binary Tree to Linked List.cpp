// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
        {
            auto temp = root->right;
            root->right = root->left;
            root->left = NULL;

            auto current = root->right;
            while (current->right != NULL)
                current = current->right;

            current->right = temp;
        }
        flatten(root->right);
    }
};
