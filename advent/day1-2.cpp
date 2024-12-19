#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solution(vector<int>& list1, vector<int>& list2) {
        unordered_map<int, int> hm;

        for (int num: list2) {
            hm[num] += 1;
        }

        int sum = 0;
        for (int num: list1) {
            sum += num * hm[num];   
        }
        return sum;
    }
};


int main() {
    ifstream input("advent/day1.txt");

    vector<int> column1, column2;
    string line;

    while (getline(input, line)) {
        istringstream iss(line);
        int num1, num2;

        if (iss >> num1 >> num2) {
            column1.push_back(num1);
            column2.push_back(num2);
        }
    }

    input.close();
    Solution s;
    cout << s.solution(column1, column2) << '\n';
    return 0;
}