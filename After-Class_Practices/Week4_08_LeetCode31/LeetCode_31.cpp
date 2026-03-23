#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        int i = n - 2;
        // 1. 從右向左找到第一個 nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // 2. 如果存在這樣的 i
        if (i >= 0) {
            int j = n - 1;
            // 從右向左找到第一個大於 nums[i] 的元素
            while (nums[j] <= nums[i]) {
                j--;
            }
            // 交換
            swap(nums[i], nums[j]);
        }
        
        // 3. 反轉 i 之後的序列，使其變成最小字典序
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// 輔助函式：用來印出 vector 的內容
void printVector(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << endl;
}

int main() {
    Solution solution;

    // 測試範例 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Original 1: ";
    printVector(nums1);
    solution.nextPermutation(nums1);
    cout << "Next Permutation: ";
    printVector(nums1); // 預期結果: 1, 3, 2

    cout << "---" << endl;

    // 測試範例 2 (已經是最大排列)
    vector<int> nums2 = {3, 2, 1};
    cout << "Original 2: ";
    printVector(nums2);
    solution.nextPermutation(nums2);
    cout << "Next Permutation: ";
    printVector(nums2); // 預期結果: 1, 2, 3

    cout << "---" << endl;

    // 測試範例 3
    vector<int> nums3 = {1, 1, 5};
    cout << "Original 3: ";
    printVector(nums3);
    solution.nextPermutation(nums3);
    cout << "Next Permutation: ";
    printVector(nums3); // 預期結果: 1, 5, 1

    return 0;
}