// https://leetcode.com/problems/unique-binary-search-trees

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> t(n + 1, 0);
        t[0] = t[1] = 1;

        for (int r = 2; r <= n; r++)
            for (int mid = 1; mid <= r; mid++)
                t[r] += t[mid - 1] * t[r - mid];

        return t[n];
    }
};
