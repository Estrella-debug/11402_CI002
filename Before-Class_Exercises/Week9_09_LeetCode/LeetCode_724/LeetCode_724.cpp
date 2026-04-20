#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        // Calculate the total sum of the array
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Check if left sum equals the right sum
            // rightSum = totalSum - leftSum - nums[i]
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            // Update leftSum for the next index
            leftSum += nums[i];
        }

        return -1; // No pivot index found
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    std::vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    int result1 = sol.pivotIndex(nums1);
    std::cout << "Example 1: Input [1, 7, 3, 6, 5, 6], Pivot Index: " << result1 << std::endl;

    // 測試範例 2
    std::vector<int> nums2 = {1, 2, 3};
    int result2 = sol.pivotIndex(nums2);
    std::cout << "Example 2: Input [1, 2, 3], Pivot Index: " << result2 << std::endl;

    // 測試範例 3
    std::vector<int> nums3 = {2, 1, -1};
    int result3 = sol.pivotIndex(nums3);
    std::cout << "Example 3: Input [2, 1, -1], Pivot Index: " << result3 << std::endl;

    return 0;
}