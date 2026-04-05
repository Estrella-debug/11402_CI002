#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 將 2D 矩陣視為 1D 有序陣列進行二分搜尋
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 核心邏輯：將 1D 索引映射回 2D 座標
            // row = index / 總列數 (n)
            // col = index % 總列數 (n)
            int mid_val = matrix[mid / n][mid % n];
            
            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;

    // 建立一個遞增的測試矩陣
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    int target2 = 13;

    // 測試範例 1
    cout << "測試目標 " << target1 << ": " 
         << (sol.searchMatrix(matrix, target1) ? "找到元素" : "未找到元素") << endl;

    // 測試範例 2
    cout << "測試目標 " << target2 << ": " 
         << (sol.searchMatrix(matrix, target2) ? "找到元素" : "未找到元素") << endl;

    return 0;
}