// https://leetcode.com/problems/longest-valid-parentheses/

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> st = {-1};
        int ans = 0;
        for (int i = 0; i < S.size(); i++)
            if (S[i] == '(')
                st.push_back(i);
            else if (st.size() == 1)
                stack[0] = i;
            else
            {
                stack.pop_back();
                ans = max(ans, i - stack.back());
            }
        return ans;
    }
};
