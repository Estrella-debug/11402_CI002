#include <iostream>
#include <vector>

using namespace std;

// 核心演算法：Boyer-Moore 投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0; 
        int count = 0;     

        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate; 
    }
};

// 本機端測試用的 main 函數
int main() {
    Solution sol;
    int n;
    int caseNum = 1;

    // 遇到 EOF 結束。每次先讀取這組測試資料的「陣列長度 n」
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        // --- 格式化印出 ---
        cout << "Example " << caseNum++ << ":" << endl;
        
        cout << "Input: nums = [";
        for (int j = 0; j < nums.size(); ++j) {
            cout << nums[j] << (j == nums.size() - 1 ? "" : ",");
        }
        cout << "]" << endl;

        // --- 執行我們的演算法 ---
        int result = sol.majorityElement(nums);

        // --- 印出 Output ---
        cout << "Output: " << result << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}