// https://leetcode.com/problems/binary-tree-pruning

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
           return root;

        auto left = pruneTree(root->left);
        root->left = left;
        
        auto right = pruneTree(root->right);
        root->right = right;

        if(root->val == 0 && root->left == NULL && root->right == NULL)
            root = NULL;
        return root;
    }
};
