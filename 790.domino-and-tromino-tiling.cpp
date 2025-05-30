/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {
        vector<long> p_cache(n + 1, 0);
        vector<long> f_cache(n + 1, 0);

        int MOD = 1'000'000'007;

        if (n <= 2)
        {
            return n;
        }
        f_cache[1] = 1L;
        f_cache[2] = 2L;
        p_cache[2] = 1L;

        for (int i = 3; i <= n; i++)
        {
            f_cache[i] = (f_cache[i - 2] + f_cache[i - 1] + 2 * p_cache[i - 1]) % MOD;
            p_cache[i] = (p_cache[i - 1] + f_cache[i - 2]) % MOD;
        }

        return static_cast<int>(f_cache[n]);
    }
};
// @lc code=end
