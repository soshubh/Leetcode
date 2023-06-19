https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, v = prices[0], p = prices[0], maxP = 0;

        while (i < prices.size() - 1)
        {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            v = prices[i];

            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            p = prices[i];

            maxP += p - v;
        }

        return maxP;
    }
};
