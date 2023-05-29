// https://leetcode.com/problems/multiply-strings/

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int l1 = num1.length();
        int l2 = num2.length();
        string s(l1 + l2, '0');

        for (int i = l1 - 1; i >= 0; i--)

            for (int j = l2 - 1; j >= 0; j--)
            {

                int mult = (num1[i] - '0') * (num2[j] - '0');

                int sum = mult + (s[i + j + 1] - '0');
                s[i + j] += sum / 10;
                s[i + j + 1] = '0' + sum % 10;
            }

        int i = s.find_first_not_of('0');
        
        if (i == -1)
            return "0";
        else
            return s.substr(i);
    }
};
