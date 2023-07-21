// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    int ml = 0;
    int a = 0;
    int n = nums.size();

    vector<int> dp(n, 1), c(n, 1);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        c[i] = c[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        c[i] += c[j];
                    }
                }
            }

            if (dp[i] > ml) {
                ml = dp[i];
                a= c[i];
            } else if (dp[i] == ml)
                a += c[i];
        }
        return a;
    }
};
