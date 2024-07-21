/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 */
#include <thread>
#include <functional>
#include <semaphore.h>

using namespace std;

// @lc code=start
class H2O {
private:
    sem_t semH;
    sem_t semO;
    int hydrogens_produced;
public:
    H2O() {
        sem_init(&semH, 0, 2);
        sem_init(&semO, 0, 1);
        hydrogens_produced = 0;        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&semH);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hydrogens_produced++;
        if (hydrogens_produced == 2) {
            sem_post(&semO);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&semO);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        hydrogens_produced = 0;
        sem_post(&semH);
        sem_post(&semH);
    }
};
// @lc code=end

