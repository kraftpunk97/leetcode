/*
 * @lc app=leetcode id=2261 lang=cpp
 *
 * [2261] K Divisible Elements Subarrays
 */

// @lc code=start
#include <cstdio>
#include <vector>
#include <tuple>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    struct Dividend {
        int pos=0;
        int val=0;
        Dividend(int pos, int val) : pos(pos), val(val) {}
    };

    long long calculateRollingHash(vector<int>& array, int start_pos, int end_pos) {
        long long p = 31, m = 1e9+07;
        long long hash_value = 0;
        long long p_pow = 1;
        const long long n = end_pos - start_pos + 1;
        for (int i=start_pos; i<=end_pos; i++) {
            hash_value = hash_value + (array[i]*p_pow) % m;
            p_pow = (p_pow*p) % m;
        }
        return hash_value;
    }

    int countDistinct(vector<int>& nums, int k, int p) {
        // Find all the subarrays that satisfy this condition.
        vector<Dividend> div_pos;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % p == 0) {
                div_pos.push_back(Dividend(i, nums[i]));
            }
        }
        // We now have the encoded sub-arrarys, but it's still possible that
        // that some of the subarrays are also the same.
        // So now we take each enocoded sub-array, expand it, find its hash and 
        // store that in a set. Finally, return the size of the set.
        set<tuple<int, int>> encoded_sub;
        if (div_pos.size() != 0) {
            for (int i=0; i<=div_pos.size()-k; i++) {
                int start_pos = (i==0) ? min(0, div_pos[0].pos) : (div_pos[i-1].pos+1);
                int end_pos = (i==div_pos.size()-k) ? max(div_pos.back().pos, static_cast<int>(nums.size()-1))
                                                    : (div_pos[i+k].pos-1);
                generateSubArrays(start_pos, end_pos, encoded_sub);
            }
        } else {
            for (int i=0; i<nums.size(); i++) {
                for (int j=i; j<nums.size(); j++) {
                    generateSubArrays(i, j, encoded_sub);
                }
            }
        }
        unordered_set<long long> unique_hashes;
        for (auto &arr: encoded_sub) {
            int start_pos = get<0>(arr);
            int end_pos = get<1>(arr);
            long long hash = calculateRollingHash(nums, start_pos, end_pos);
            unique_hashes.insert(hash);
        }
        return unique_hashes.size();

    }

    void generateSubArrays(int start_pos, int end_pos, set<tuple<int, int>> &encoded_sub) {
        for (int i=start_pos; i<=end_pos; i++) {
            for (int j=i; j<=end_pos; j++) {
                tuple<int, int> enc(i, j);
                encoded_sub.insert(enc);
            }
        }
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<int> nums({14, 11, 6, 9, 3, 15});
    int k = 4, p = 7;
    sol.countDistinct(nums, k, p);
    return 0;
}
