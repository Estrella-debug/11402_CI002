#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            // Prevent potential overflow compared to (low + high) / 2
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                low = mid + 1; // Search right half
            } else {
                high = mid - 1; // Search left half
            }
        }
        
        // If not found, 'low' is the index where target would be inserted
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};

    // 測試範例 1：目標值存在於陣列中
    int target1 = 5;
    cout << "Example 1: Target " << target1 << " is at index: " 
         << sol.searchInsert(nums, target1) << endl; // 預期輸出: 2

    // 測試範例 2：目標值不存在，應插入在中間位置
    int target2 = 2;
    cout << "Example 2: Target " << target2 << " should be inserted at: " 
         << sol.searchInsert(nums, target2) << endl; // 預期輸出: 1

    // 測試範例 3：目標值不存在，應插入在最後面
    int target3 = 7;
    cout << "Example 3: Target " << target3 << " should be inserted at: " 
         << sol.searchInsert(nums, target3) << endl; // 預期輸出: 4

    // 測試範例 4：目標值不存在，應插入在最前面
    int target4 = 0;
    cout << "Example 4: Target " << target4 << " should be inserted at: " 
         << sol.searchInsert(nums, target4) << endl; // 預期輸出: 0

    return 0;
}