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
        
        for (int i=0; i<n; i++) {
            ages_scores.push_back(tuple<int, int>({ages[i], scores[i]}));
        }

        sort(ages_scores.begin(), ages_scores.end());

        // If you choose to include a player,
        // you must only choose players with at least that score later on.
        vector<int> max_player_score;

        max_player_score.push_back(get<1>(ages_scores[0]));
        for (int i=1; i<n; i++) { // For a player we are considering including...
            int this_player_score = get<1>(ages_scores[i]);
            int this_player_max_score = this_player_score; // The max score achievable by including any player has to include that player's score.
            for (int j=i-1; j >= 0; j--) { // We go thru all the players we have seen before this guy;
                int that_player_score = get<1>(ages_scores[j]);
                if (that_player_score <= this_player_score) {  // Since ages_scores is sorted by age and then scores, we know that ages_scores[i].age >= ages_scores[j].age
                // So all we need to do is check the scores.
                    int score = this_player_score + max_player_score[j]; // Means that we can include this player's score.
                    if (score > this_player_max_score) {  // Simply calc the max score achieveable by including this player, based on all the players we have seen so far.
                        this_player_max_score = score;
                    }
                }
            }
            max_player_score.push_back(this_player_max_score);
        }
        
        int max_score = 0;
        for (int score: max_player_score) {
            max_score = max(max_score, score);
        }
        return max_score;
    }

    void printVec(vector<int>& vec) {
        for (auto& elem: vec) {
            cout << elem << '\n';
        }
    }
};
// @lc code=end

// If you choose to take a player, you are essentially also choosing all the players that were chosen to get to that player. In which case, The score will be just add score of your current player to the scores_table[i], so what