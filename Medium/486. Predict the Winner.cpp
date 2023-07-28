// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        
        for (int d=1; d<n; d++)
         for (int j=n-1; j-d>=0; j--)
         {
             int t=j-d;
             dp[j]=max((nums[t]-dp[j]), (nums[j]-dp[j-1]));
         }

    return dp[n-1]>=0;
    }
};
