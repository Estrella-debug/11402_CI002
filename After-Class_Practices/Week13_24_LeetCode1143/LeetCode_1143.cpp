#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        // dp[i][j] 儲存的是 text1[0...i-1] 與 text2[0...j-1] 的 LCS 長度
        // 大小宣告為 (m+1) x (n+1)，預設初始化為 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    // 如果當前字元匹配成功，長度等於「左上方格子的值 + 1」
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // 如果不匹配，取「上方格子」與「左方格子」的最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // 右下角的值即為最終的 LCS 長度
        return dp[m][n];
    }
};

int main() {
    Solution sol;

    // 測試範例 1: 有間隔的匹配
    // text1 = "abcde", text2 = "ace"
    // 最長公共子序列為 "ace"，長度為 3
    string t1_1 = "abcde", t2_1 = "ace";
    cout << "Example 1 Result: " << sol.longestCommonSubsequence(t1_1, t2_1) << " (Expected: 3)" << endl;

    // 測試範例 2: 完全相同
    string t1_2 = "abc", t2_2 = "abc";
    cout << "Example 2 Result: " << sol.longestCommonSubsequence(t1_2, t2_2) << " (Expected: 3)" << endl;

    // 測試範例 3: 完全沒有共同子序列
    string t1_3 = "abc", t2_3 = "def";
    cout << "Example 3 Result: " << sol.longestCommonSubsequence(t1_3, t2_3) << " (Expected: 0)" << endl;

    return 0;
}