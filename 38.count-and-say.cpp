/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "1";
        for (int i = 1; i < n; i++)
        {
            res = rle(res);
        }
        return res;
    }

    string rle(string n)
    {
        string res = "";
        int repeat_counter = 1;
        for (int i = 1; i < n.length(); i++)
        {
            if (n[i] != n[i - 1])
            {
                res += to_string(repeat_counter) + n[i - 1];
                repeat_counter = 1;
            }
            else
            {
                repeat_counter += 1;
            }
        }
        res += to_string(repeat_counter) + n.back();
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    // cout << s.rle("1") << '\n';
    cout << s.countAndSay(5) << '\n';
    return 0;
}