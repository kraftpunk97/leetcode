/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size();
        int len2 = s2.size();

        if (len1 > len2)
        {
            return false;
        }

        map<char, int> ground_truth;
        set<char> s1_chars;
        for (char c : s1)
        {
            ground_truth[c] += 1;
            s1_chars.insert(c);
        }
        ground_truth['\0'] = 0;

        map<char, int> window;
        window['\0'] = 0;
        int window_len = len1;
        for (int i = 0; i < window_len; i++)
        {
            if (s1_chars.find(s2[i]) == s1_chars.end())
            {
                window['\0'] += 1;
            }
            else
            {
                window[s2[i]] += 1;
            }
        }
        if (window == ground_truth)
        {
            return true;
        }

        int window_start = 1;
        int window_end = window_len;
        while (window_end < len2)
        {

            char c_remove = s2[window_start - 1];
            char c_insert = s2[window_end];
            if (s1_chars.find(c_remove) == s1_chars.end())
            {
                window['\0'] -= 1;
            }
            else
            {
                window[c_remove] -= 1;
            }
            if (s1_chars.find(c_insert) == s1_chars.end())
            {
                window['\0'] += 1;
            }
            else
            {
                window[c_insert] += 1;
            }

            if (window == ground_truth)
            {
                return true;
            }

            window_start++;
            window_end++;
        }

        return false;
    }
};
// @lc code=end
