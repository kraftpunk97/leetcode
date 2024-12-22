/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    struct Car {
        int pos;
        int vel;
        Car(int pos, int vel) : pos(pos), vel(vel) {}
        Car() { Car(0, 0); }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Stack based approach.
        int n = position.size();
        vector<Car> cars(n);
        
        for (int i=0; i<n; i++) {
            cars[i].pos = position[i];
            cars[i].vel = speed[i];
        }

        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) { return a.pos < b.pos; });

        
        stack<float> st;
        for (auto& car:  cars) {
            float time = (target - car.pos) / (float)car.vel;
            while (!st.empty() && time>=st.top()) { st.pop(); }
            st.push(time);
        }
        return st.size();
    }
};
// @lc code=end

int main() {
    vector<int> position{10,8,0,5,3};
    vector<int> speed{2,4,1,1,3};
    int target = 12;

    Solution s;
    cout << s.carFleet(target, position, speed) << '\n';
    return 0;
}