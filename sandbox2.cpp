#include <chrono>
#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string line = "SetCol 32 2";

    regex re("SetCol");
    smatch sm;
    auto start = chrono::high_resolution_clock::now();
    if (regex_search(line.cbegin(), line.cend(), sm, re)) {
        
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);

    cout << duration.count() << "\n";
    return 0;
}