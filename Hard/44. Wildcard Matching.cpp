// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                
                if (i == 0 && j == 0)
                 continue;
                
                if (j == 0)
                 continue;

                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j-1];
                    if (i > 0) 
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    
                }
                else if (i > 0 && (p[j - 1] == '?' || s[i-1] == p[j-1]))
                    dp[i][j] = dp[i-1][j-1];
                
            }
        }
        return dp[m][n];
    }
};
