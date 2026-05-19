#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // 如果起點本身就是障礙物，那根本無法出發，直接回傳 0
        if (obstacleGrid[0][0] == 1) return 0;
        
        // DP 陣列初始化為 0，大小為列數 (n)
        vector<long long> dp(n, 0);
        dp[0] = 1; // 起點初始化為 1 種走法
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // 遇到障礙物：到達此格的路徑數歸零
                } else if (j > 0) {
                    // 當前格子路徑數 = 上方格子的路徑數 (更新前的 dp[j]) 
                    //                    + 左方格子的路徑數 (剛剛更新完的 dp[j-1])
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return (int)dp[n - 1];
    }
};

int main() {
    Solution sol;

    // 測試範例 1：中間有一個障礙物
    // 網格：
    // [0, 0, 0]
    // [0, 1, 0]
    // [0, 0, 0]
    vector<vector<int>> grid1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << "Example 1 Result: " << sol.uniquePathsWithObstacles(grid1) << " (Expected: 2)" << endl;

    // 測試範例 2：障礙物堵住出口附近
    // 網格：
    // [0, 1]
    // [0, 0]
    vector<vector<int>> grid2 = {
        {0, 1},
        {0, 0}
    };
    cout << "Example 2 Result: " << sol.uniquePathsWithObstacles(grid2) << " (Expected: 1)" << endl;

    // 測試範例 3：終點是障礙物
    vector<vector<int>> grid3 = {
        {0, 0},
        {0, 1}
    };
    cout << "Example 3 Result: " << sol.uniquePathsWithObstacles(grid3) << " (Expected: 0)" << endl;

    return 0;
}