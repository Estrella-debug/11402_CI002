#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // 排除小於等於 0 的情況
        while (n % 3 == 0) {
            n /= 3; // 持續除以 3
        }
        return n == 1; // 最終為 1 → 是 3 的冪次方
    }
};

int main() {
    Solution sol;
    int testNum;

    cout << "Please enter a number: ";
    cin >> testNum;

    if (sol.isPowerOfThree(testNum)) {
        cout << testNum << " is a power of three." << endl;
    } else {
        cout << testNum << " is not a power of three." << endl;
    }

    return 0;
}