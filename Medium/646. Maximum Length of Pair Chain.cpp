// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty())
         return 0;
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        
        vector<int> l(n, 1);
        for (int i = 1; i < n; i++) 
            for (int j = 0; j < i; j++) 
                if (pairs[j][1] < pairs[i][0]) 
                 l[i] = max(l[i], l[j] + 1); 
        
        return l.back();
    }
};
