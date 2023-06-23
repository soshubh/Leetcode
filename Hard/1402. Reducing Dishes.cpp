// https://leetcode.com/problems/reducing-dishes

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {

        int a = 0;
        int sumSf = 0;
        sort(satisfaction.begin(), satisfaction.end(), greater<>());

        for (auto s : satisfaction)
        {
            sumSf += s;
            if (sumSf <= 0)
                return a;
            a += sumSf;
        }
        return a;
    }
};
