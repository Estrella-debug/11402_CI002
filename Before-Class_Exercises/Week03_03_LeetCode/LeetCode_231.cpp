#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1)
            return false;
        string bins = toBinary(n);
        int count = 0;
        for(char& c : bins) {
            if(c == '1')
                count++;
        }
        return count == 1;
    }

private:
    string toBinary(int n){
        string bins;
        while(n != 0){
            bins += (n % 2 == 0 ? "0": "1");
            n /= 2;
        }
        return bins;
    }
};

// --- Added main function ---
int main() {
    Solution sol;
    
    // Test cases
    vector<int> tests = {1, 16, 3, 0, -8};
    
    for(int n : tests) {
        if(sol.isPowerOfTwo(n)) {
            cout << n << " is a power of two." << endl;
        } else {
            cout << n << " is NOT a power of two." << endl;
        }
    }
    
    return 0;
}