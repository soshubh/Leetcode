// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        vector<int> st = {-1};
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(')
             st.push_back(i);
            else if (st.size() == 1)
             st[0] = i;
            else {
                st.pop_back();
                ans = max(ans, i - st.back());
            }
        return ans;
    
    }
};
