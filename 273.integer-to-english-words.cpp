/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
    unordered_map<int, string> map;
    void initMap() {
        map[1] = "One";
        map[2] = "Two";
        map[3] = "Three";
        map[4] = "Four";
        map[5] = "Five";
        map[6] = "Six";
        map[7] = "Seven";
        map[8] = "Eight";
        map[9] = "Nine";
        map[10] = "Ten";
        map[11] = "Eleven";
        map[12] = "Twelve";
        map[13] = "Thirteen";
        map[14] = "Fourteen";
        map[15] = "Fifteen";
        map[16] = "Sixteen";
        map[17] = "Seventeen";
        map[18] = "Eighteen";
        map[19] = "Nineteen";
        map[20] = "Twenty";
        map[30] = "Thirty";
        map[40] = "Forty";
        map[50] = "Fifty";
        map[60] = "Sixty";
        map[70] = "Seventy";
        map[80] = "Eighty";
        map[90] = "Ninety";
        map[100] = "Hundred";
    }
public:

    inline void trim(string &s) {
        if (s[0] == ' ') { s.erase(0, 1); }
        if (s.back() == ' ') { s.erase(s.length()-1, 1); }
    }

    string numberToWords(int num) {
        initMap();
        vector<string> groups;
        
        if (num == 0) { return "Zero"; }

        int digits = 0;
        while (num != 0) {
            digits = num % 1000;
            num = num / 1000;
            if (digits != 000) { 
                groups.push_back(processThreeDigits(digits));
            } else { groups.push_back(""); }
        }
        string result = "";
        int counter = groups.size();
        for (int i=groups.size()-1; i>=0; i--) {
            string group = groups[i];
            if (group.empty()) {
                counter--;
                continue;
            }
            string denomination = "";
            switch (counter) {
                case 4: denomination = " Billion ";
                break;
                case 3: denomination = " Million ";
                break;
                case 2: denomination = " Thousand ";
                break;
            }
            counter--;
            result += group + denomination;
        }
        trim(result);
        return result;
    }

    string processThreeDigits(int digits) {
        string result = "";
         
        int hundred = digits / 100;
        if (hundred != 0) { result += map[hundred] + " " + map[100]; }
        digits = digits % 100;

        if (digits>=10 && digits<=19) {
            result += " " + map[digits];
        } else { // digits<=9 && digits>=20
            int ten = digits / 10;
            if (ten != 0) { result += " " + map[ten*10]; }
            digits = digits % 10;

            int unit = digits;
            if (unit != 0) { result += " " + map[unit]; }
        }
        trim(result);
        return result;
    }

    template <typename T>
    void printVec(vector<T> &vec) {
        for (auto elem: vec) {
            cout << elem << '\n';
        }
    }
};
// @lc code=end


int main() {
    Solution s;
    cout << s.numberToWords(1001) << '\n';
    return 0;
}
