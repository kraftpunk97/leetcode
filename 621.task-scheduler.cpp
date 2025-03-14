/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
#include<bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m['Z'+1] = {0};
        for (char task: tasks) { m[task] += 1; }

        auto comparatorFunc = [m](char a, char b) { return m[a]==m[b] ? a<b : m[a]<m[b]; };
        priority_queue<char, vector<char>, decltype(comparatorFunc)> maxHeap{comparatorFunc};

        for (char task='A'; task<='Z'; task++) {
            if (m[task] != 0) { maxHeap.push(task); }
        }

        int numIntervals = 0;
        while (!maxHeap.empty()) {
            vector<char> poppedTasks;
            for (int i=0; i<=n; i++) {
                if (maxHeap.empty() && !poppedTasks.empty()) { numIntervals++; }
                if (!maxHeap.empty()) {
                    char task = maxHeap.top();
                    numIntervals++;
                    maxHeap.pop();
                    m[task]--;
                    if (m[task] > 0) { poppedTasks.push_back(task); }
                }
            }
            for (char task: poppedTasks) { maxHeap.push(task); }
        }

        return numIntervals;
    }
};
// @lc code=end

