// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

class Solution {
public:
    int c = 0;
    TreeNode* bstToGst(TreeNode* root) {
    if (root->right != NULL) 
        bstToGst(root->right);
    
    c = root->val = c + root->val;
    if (root->left != NULL)
        bstToGst(root->left);
    return root;
    }
};
