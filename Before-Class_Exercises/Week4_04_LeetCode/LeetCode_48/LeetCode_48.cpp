#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;
    int n;
    int caseNum = 1;

    // 讀取矩陣的長寬 n (這題保證是 n x n 的正方形矩陣)
    while (cin >> n) {
        // 宣告一個 n x n 的二維陣列
        vector<vector<int>> matrix(n, vector<int>(n));
        
        // 讀取二維陣列的資料
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "Example " << caseNum++ << ":" << endl;
        
        // 執行原地旋轉
        sol.rotate(matrix);

        // 印出旋轉後的結果
        cout << "Output: [" << endl;
        for (int i = 0; i < n; i++) {
            cout << "  [";
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << (j == n - 1 ? "" : ",");
            }
            cout << "]" << (i == n - 1 ? "" : ",") << endl;
        }
        cout << "]" << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}