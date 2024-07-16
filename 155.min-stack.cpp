/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <stack>
using namespace std;

// @lc code=start
class MinStack {
    stack<int> stck;
    stack<int> min_stck;
    bool does_min_exist = false;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (!does_min_exist) {
            does_min_exist = true;
            min_stck.push(val);
        } else {
            if (val <= min_stck.top()) {
                min_stck.push(val);
            }
        }
        stck.push(val);
    }
    
    void pop() {
        if(!min_stck.empty() && !stck.empty() && min_stck.top()==stck.top()) {
            min_stck.pop();
        }
        stck.pop();
        does_min_exist = !stck.empty();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return min_stck.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

