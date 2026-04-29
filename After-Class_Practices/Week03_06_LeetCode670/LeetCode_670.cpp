#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        // 1. 紀錄 0-9 每個數字最後一次出現的位置
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        
        // 2. 從左到右遍歷每個位數
        for (int i = 0; i < n; ++i) {
            // 3. 嘗試找一個比當前數位 s[i] 還大的數字 (從 9 開始往下找)
            for (int d = 9; d > s[i] - '0'; --d) {
                // 如果這個較大的數字 d 存在，且它的位置在當前位置 i 之後
                if (last[d] > i) {
                    // 執行交換
                    swap(s[i], s[last[d]]);
                    // 因為只能交換一次，達成目標後直接轉回整數返回
                    return stoi(s);
                }
            }
        }
        
        // 如果遍歷完都沒交換，代表原本就是最大值
        return num;
    }
};

int main() {
    Solution sol;

    // 測試案例
    vector<int> testCases = {2736, 9973, 98368, 1993};

    cout << "--- Maximum Swap Test ---" << endl;
    for (int num : testCases) {
        int result = sol.maximumSwap(num);
        cout << "Original: " << num << " \t-> After Swap: " << result << endl;
    }

    return 0;
}