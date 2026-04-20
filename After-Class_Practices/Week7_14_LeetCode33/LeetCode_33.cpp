#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // 判斷 mid 左邊是否為有序
            if (nums[left] <= nums[mid]) {
                // 左半部分有序，判斷 target 是否在左半部分內
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // 否則右半部分有序
            else {
                // 右半部分有序，判斷 target 是否在右半部分內
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1; // 找不到
    }
};

int main() {
    Solution sol;

    // 測試範例 1：旋轉點在中間，搜尋目標在旋轉後的部分
    // 原始：[0, 1, 2, 4, 5, 6, 7] -> 旋轉：[4, 5, 6, 7, 0, 1, 2]
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int result1 = sol.search(nums1, target1);
    cout << "Example 1: Input [4, 5, 6, 7, 0, 1, 2], Target 0, Index: " << result1 << endl;

    // 測試範例 2：目標不存在於陣列中
    int target2 = 3;
    int result2 = sol.search(nums1, target2);
    cout << "Example 2: Input [4, 5, 6, 7, 0, 1, 2], Target 3, Index: " << result2 << endl;

    // 測試範例 3：陣列只有一個元素
    vector<int> nums3 = {1};
    int target3 = 0;
    int result3 = sol.search(nums3, target3);
    cout << "Example 3: Input [1], Target 0, Index: " << result3 << endl;

    return 0;
}