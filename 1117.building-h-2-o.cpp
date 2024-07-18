/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 */
#include <thread>
#include <functional>

using namespace std;

// @lc code=start
class H2O {
private:
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
    }
};
// @lc code=end

