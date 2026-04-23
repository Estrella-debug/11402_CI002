#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        // 矩陣有序，所以最小值在左上角，最大值在右下角
        int left = matrix[0][0], right = matrix[n-1][n-1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 算一下矩陣中有多少數字小於或等於 mid
            if (countLessEqual(matrix, mid, n) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int row = n - 1, col = 0;
        // 從左下角開始走「階梯」，可以在 O(n) 時間內算出有多少數值 <= mid
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                // 如果當前數字 <= mid，代表這整行 (從 0 到 row) 都符合條件
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    // 矩陣：
    // [ 1,  5,  9]
    // [10, 11, 13]
    // [12, 13, 15]
    // 尋找第 8 小的數字
    vector<vector<int>> matrix1 = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k1 = 8;
    int result1 = sol.kthSmallest(matrix1, k1);
    cout << "Example 1: The " << k1 << "th smallest element is: " << result1 << endl;
    // 預期輸出: 13

    // 測試範例 2
    // 矩陣：[[-5]]
    // 尋找第 1 小的數字
    vector<vector<int>> matrix2 = {{-5}};
    int k2 = 1;
    int result2 = sol.kthSmallest(matrix2, k2);
    cout << "Example 2: The " << k2 << "st smallest element is: " << result2 << endl;
    // 預期輸出: -5

    return 0;
}