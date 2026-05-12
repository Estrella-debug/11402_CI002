#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 使用一維陣列 DP，dp[j] 表示到達目前行第 j 列的總路徑數
        // 第一行初始化為 1，因為只有一種一路向右走的方法
        vector<int> dp(n, 1); 
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // dp[j] 在更新前代表「上方格子」的路徑數
                // dp[j-1] 代表「左方格子」的路徑數
                // 更新後的 dp[j] = 上方 + 左方
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};

int main() {
    Solution sol;

    // 測試範例 1: 3x7 網格
    int m1 = 3, n1 = 7;
    cout << "Example 1 (3x7): " << sol.uniquePaths(m1, n1) << " (Expected: 28)" << endl;

    // 測試範例 2: 3x2 網格
    int m2 = 3, n2 = 2;
    cout << "Example 2 (3x2): " << sol.uniquePaths(m2, n2) << " (Expected: 3)" << endl;

    // 測試範例 3: 7x3 網格 (結果應該與 3x7 相同)
    int m3 = 7, n3 = 3;
    cout << "Example 3 (7x3): " << sol.uniquePaths(m3, n3) << " (Expected: 28)" << endl;

    return 0;
}