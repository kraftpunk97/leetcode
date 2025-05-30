/*
 * @lc app=leetcode id=2332 lang=cpp
 *
 * [2332] The Latest Time to Catch a Bus
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int maxWaitingTime = passengers[0];
        int passengerIdx = 0, busIdx = 0;
        int busCapacity = capacity - 1;
        while (busIdx < buses.size() && passengerIdx < passengers.size())
        {
            if (busCapacity < 0 || maxWaitingTime > buses[busIdx])
            { // Bus will depart
                busIdx += 1;
                busCapacity = capacity - 1;
                continue;
            }

            passengerIdx += 1;
            if (passengers[passengerIdx-1] != passengers[passengerIdx])
            {
                maxWaitingTime = passengers[passengerIdx-1];
                busCapacity -= 1;
            }
        }

        if (passengerIdx >= passengers.size() && busIdx < buses.size())
        {
            maxWaitingTime = *buses.end();
        }

        return maxWaitingTime;
    }
};
// @lc code=end
