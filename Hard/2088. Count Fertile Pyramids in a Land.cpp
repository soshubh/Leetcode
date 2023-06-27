// https://leetcode.com/problems/count-fertile-pyramids-in-a-land/

class Solution
{
public:
    int countPyramids(vector<vector<int>> &grid)
    {
        int a = count(grid);
        reverse(grid.begin(), grid.end());
        a += count(grid);
        return a;
    }
    
    int count(vector<vector<int>> dp)
    {
        int a = 0;
        for (int i = dp.size() - 2; i >= 0; i--)
            for (int j = 1; j + 1 < dp[0].size(); j++)
                if (dp[i][j] == 1)
                {
                    dp[i][j] =
                        min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
                    a += dp[i][j] - 1;
                }
        return a;
    }
};
