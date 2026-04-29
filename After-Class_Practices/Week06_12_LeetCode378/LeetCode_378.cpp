#include <iostream>
#include <vector>

// 這裡是原本的 Solution 類別
class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(matrix, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

private:
    int countLessEqual(const std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix.size();
        int count = 0;
        int row = n - 1; 
        int col = 0;
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += (row + 1); 
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};

// 補上測試用的 main 函式
int main() {
    Solution sol;

    // 建立一個排序好的矩陣範例
    std::vector<std::vector<int>> matrix = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;
    int result = sol.kthSmallest(matrix, k);

    // 輸出結果
    std::cout << "The " << k << "-th smallest element is: " << result << std::endl;

    return 0;
}