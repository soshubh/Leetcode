// https://leetcode.com/problems/permutation-sequence

class Solution
{
public:
    string getPermutation(int n, int k)
    {

        string ans;
        vector<int> nums(n);
        vector<int> fact(n + 1, 1);

        iota(nums.begin(), nums.end(), 1);

        for (int i = 2; i <= n; ++i)
            fact[i] = fact[i - 1] * i;

        k--;

        for (int i = n - 1; i >= 0; --i)
        {
            int j = k / fact[i];
            k = k % fact[i];
            ans = ans + to_string(nums[j]);
            nums.erase(nums.begin() + j);
        }

        return ans;
    }
};
