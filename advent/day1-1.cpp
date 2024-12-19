#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distanceCalc(vector<int>& list1, vector<int>& list2) {
        int n = list2.size();

        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());

        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += abs(list1[i]-list2[i]);
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
    cout << s.distanceCalc(column1, column2) << '\n';
    return 0;
}