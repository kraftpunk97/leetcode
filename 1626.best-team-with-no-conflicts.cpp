/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <tuple>

using namespace std;

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // First, sort players by age and break ties by their score.
        // You can now consider the players from left to right.        
        int n = scores.size();
        vector<tuple<int, int>> ages_scores;
        for (tuple<int&, int&> elem: views::zip(ages, scores)) {
            ages_scores.push_back(elem);
        }
        sort(ages_scores.begin(), ages_scores.end(),
                [](tuple<int, int>a, tuple<int, int>b) { 
                    return get<0>(b)==get<0>(a) ? get<1>(b)<get<1>(a) : get<0>(b)<get<0>(a);
        });
        // If you choose to include a player,
        // you must only choose players with at least that score later on.


    }
};
// @lc code=end

int main() {
    return 0;
}
