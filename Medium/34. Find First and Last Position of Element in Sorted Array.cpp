// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {

        int l = lower_bound(n.begin(), n.end(), t) - n.begin();
        int r = lower_bound(n.begin(), n.end(), t + 1) - n.begin();
        
        if (l == r)
          return {-1, -1};
          
        return {l, r - 1};
    }
};
