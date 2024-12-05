/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, vector<string>> letter_logs;
        vector<string> digit_logs;
        vector<string> result;

        for (auto log: logs) {
            // Get content
            int delimiterPos = 0;
            while (log[delimiterPos++] != ' ');
            delimiterPos--;
            
            string identifier = log.substr(0, delimiterPos);
            string content = log.substr(delimiterPos+1, log.length()-delimiterPos+1);

            if (content[0] < 'a') { // Digit log
                digit_logs.push_back(log);
            } else { // Letter logs
                if (letter_logs.find(content) == letter_logs.end()) { // Record not found
                    letter_logs[content] = vector<string>({identifier});
                } else {
                    letter_logs[content].push_back(identifier);
                }
            }
        }

        // Add text logs to the results
        for (auto& pair: letter_logs) {
            sort(pair.second.begin(), pair.second.end());  // Sorting the text based on identifier lexiographically
            
            for (const auto& identifier: pair.second) {
                result.push_back(identifier+" "+pair.first);
            }
        }
        result.insert(result.end(), digit_logs.begin(), digit_logs.end()); // Finally adding the digit logs
        return result;

    }
};
// @lc code=end

