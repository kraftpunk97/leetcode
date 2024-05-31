/*
 * @lc app=leetcode id=2260 lang=cpp
 *
 * [2260] Minimum Consecutive Cards to Pick Up
 */

#include <cstdio>
#include <vector>
#include <unordered_map>


// @lc code=start
class Solution {
public:
    int minimumCardPickup(std::vector<int>& cards) {
        std::unordered_map<int, int> last_position;
        int min_dist = INT_MAX;
        for (int i=0; i<cards.size(); i++) {
            int card = cards[i];
            if (last_position.find(card) != last_position.end()) {
                int dist = i-last_position[card]+1;
                min_dist = min_dist<dist ? min_dist : dist;
            }
            last_position[card] = i;
        }
        return min_dist==INT_MAX ? -1 : min_dist;
    }
};
// @lc code=end

int main() {
    return 0;
}