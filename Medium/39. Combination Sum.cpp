// https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    void combi(vector<int> &candidates, int curr, int target, int sum, vector<int> temp, vector<vector<int>> &ans)
    {

        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }

        if (sum > target)
            return;

        if (curr == candidates.size())
            return;

        vector<int> a = temp;
        a.push_back(candidates[curr]);

        combi(candidates, curr, target, sum + candidates[curr], a, ans);

        combi(candidates, curr + 1, target, sum, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> a;
        vector<int> t;
        combi(candidates, 0, target, 0, t, a);
        return a;
    }
};
