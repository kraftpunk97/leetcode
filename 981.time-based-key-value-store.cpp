/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
namespace lc {
    struct Value{
        string value;
        int ts;

        Value(string val, int ts) : value(val), ts(ts) {}
    };
}
class TimeMap {
    unordered_map<string, vector<lc::Value>> hm;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hm[key].push_back(lc::Value(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (hm.find(key) == hm.end()) { return ""; }
        else {
            vector<lc::Value>& arr = hm[key];
            if (timestamp < arr[0].ts) { return ""; }
            else {
                int l = 0;
                int r = arr.size()-1;

                while (l <= r) {
                    int m = l + ((r-l)/2);
                    if (arr[m].ts < timestamp) { l = m + 1; }
                    else if (arr[m].ts > timestamp) { r = m - 1; }
                    else {
                        return arr[m].value;
                    }
                }
                return arr[r].value;
            }

        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

int main() {
    TimeMap tm;
    tm.set("foo", "bar", 1);
    cout << tm.get("foo", 1) << '\n';
    cout << tm.get("foo", 3) << '\n';
    tm.set("foo", "bar2", 4);
    cout << tm.get("foo", 4) << '\n';
    cout << tm.get("foo", 5) << '\n';
}