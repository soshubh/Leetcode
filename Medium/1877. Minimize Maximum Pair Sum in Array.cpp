// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int a = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0, j = nums.size() - 1; i < j;)
            a = max(a, nums[i++] + nums[j--]);
        return a;
    }
};
