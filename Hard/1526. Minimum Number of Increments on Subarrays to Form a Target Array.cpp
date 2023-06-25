// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int t = target[0];

        int n = target.size();

        for (int i = 1; i < n; ++i)
            t += max(target[i] - target[i - 1], 0);

        return t;
    }
};
