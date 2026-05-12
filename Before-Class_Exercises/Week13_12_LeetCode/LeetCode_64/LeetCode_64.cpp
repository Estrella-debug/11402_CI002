#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 遍歷網格，計算到達每個位置的最小路徑和
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue; // 起點不處理
                } else if (i == 0) {
                    // 第一行只能從左邊過來
                    grid[i][j] += grid[i][j - 1];
                } else if (j == 0) {
                    // 第一列只能從上邊過來
                    grid[i][j] += grid[i - 1][j];
                } else {
                    // 選擇上方或左方較小的值加進來
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        
        // 返回右下角的值，即為最終最小路徑和
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    // 輸入: 
    // [1, 3, 1]
    // [1, 5, 1]
    // [4, 2, 1]
    // 最小路徑: 1 -> 3 -> 1 -> 1 -> 1, 總和為 7
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Example 1 Result: " << sol.minPathSum(grid1) << " (Expected: 7)" << endl;

    // 測試範例 2
    // 輸入:
    // [1, 2, 3]
    // [4, 5, 6]
    // 最小路徑: 1 -> 2 -> 3 -> 6, 總和為 12
    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Example 2 Result: " << sol.minPathSum(grid2) << " (Expected: 12)" << endl;

    return 0;
}