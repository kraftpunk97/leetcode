/*
 * @lc app=leetcode id=3343 lang=cpp
 *
 * [3343] Count Number of Balanced Permutations
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        int counter[10] = {0};
        for (auto digit : num)
        {
            counter[digit - '0'] += 1;
        }
    }

    bool isCounterEmpty(int *counter)
    {
        for (int i = 0; i < 10; i++)
        {
            if (counter[i] > 0)
            {
                return false;
            }
        }
        return true;
    }

    void topDown(int i, string num, int target, vector<vector<int>> &dp, vector<int> &remainingCounter, vector<int> &takenCounter)
    {
        if (i == n)
    }

    
};
// @lc code=end
