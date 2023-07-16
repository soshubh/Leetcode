// https://leetcode.com/problems/all-possible-full-binary-trees

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int N)
    {
        if (N == 1)
        {
            vector<TreeNode *> ans;
            TreeNode *node = new TreeNode(0);
            ans.push_back(node);
            return ans;
        }
        else if (N % 2 == 0)
        {
            vector<TreeNode *> ans;
            return ans;
        }
        else
        {
            vector<TreeNode *> ans;

            for (int lnum = 1; lnum <= N - 1 - 1; lnum += 2)
            {
                int rnum = N - 1 - lnum;
                vector<TreeNode *> ltree = allPossibleFBT(lnum);
                vector<TreeNode *> rtree = allPossibleFBT(rnum);
                for (int ltreeix = 0; ltreeix < ltree.size(); ltreeix++)
                {
                    for (int rtreeix = 0; rtreeix < rtree.size(); rtreeix++)
                    {
                        TreeNode *node = new TreeNode(0);
                        node->left = ltree[ltreeix];
                        node->right = rtree[rtreeix];
                        ans.push_back(node);
                    }
                }
            }
            return ans;
        }
    }
};
