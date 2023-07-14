// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> memo(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(matrix, i, j, INT_MIN, memo));

        return ans;
    }

    int dfs(vector<vector<int>> &matrix, int i, int j, int p,
            vector<vector<int>> &m)
    {

        if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size())
            return 0;
        if (matrix[i][j] <= p)
            return 0;

        int &a = m[i][j];

        if (a > 0)
            return a;

        int c = matrix[i][j];
        return ans = 1 + max({dfs(matrix, i + 1, j, c, m), dfs(matrix, i - 1, j, c, m),
                              dfs(matrix, i, j + 1, c, m), dfs(matrix, i, j - 1, c, m)});
    }
};
