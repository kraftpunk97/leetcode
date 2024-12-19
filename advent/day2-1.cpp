#include <bits/stdc++.h>

using namespace std;

int numSafeReports(vector<vector<int>>& unusual_data) {
    int num_safe = 0;
    int row_num=0;
    enum Trend {increasing, decreasing};
    for (auto report: unusual_data) {
        int n = report.size();
        Trend trend;
        if (report[0] == report[1]) { continue; }
        else if (report[0] < report[1]) { trend = increasing; }
        else { trend = decreasing; }
        int ctr = 1;
        bool safe = true;
        while (ctr < n) {
            if (trend==increasing && (report[ctr]-report[ctr-1]<1||report[ctr]-report[ctr-1]>3)) {
                safe = false;
                break;
            }
            if (trend==decreasing && (report[ctr-1]-report[ctr]<1||report[ctr-1]-report[ctr]>3)) {
                safe = false;
                break;
            }
            ctr++;
        }
        if (safe) {
            for (int i: report) { cout << i << ' '; } 
            cout << '\n';
            num_safe++; }
    }
    return num_safe;
}

int main() {
    ifstream input("advent/day2.txt");

    vector<vector<int>> unsafe_data;
    string line;
    int num;

    while (getline(input, line)) {
        istringstream iss(line);
        vector<int> report;

        while (iss >> num) { report.push_back(num); }
        unsafe_data.push_back(report);
    }

    input.close();
    cout << numSafeReports(unsafe_data) << '\n';
    return 0;
}