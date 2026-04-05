#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // [left, right] inclusive

        while (left <= right) {
            // 使用此公式防止 (left + right) 可能產生的整數溢位
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // 找到目標，回傳索引
            } else if (nums[mid] < target) {
                left = mid + 1; // 目標在右半部
            } else {
                right = mid - 1; // 目標在左半部
            }
        }

        return -1; // 未找到目標
    }
};

int main() {
    Solution sol;
    
    // 二分搜尋的前提：陣列必須是「已排序」的
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    // 呼叫搜尋函式
    int result = sol.search(nums, target);

    // 輸出結果
    if (result != -1) {
        std::cout << "目標 " << target << " 位於索引位置: " << result << std::endl;
    } else {
        std::cout << "陣列中找不到目標 " << target << std::endl;
    }

    // 測試找不到的情況
    target = 2;
    result = sol.search(nums, target);
    if (result == -1) {
        std::cout << "目標 " << target << " 不存在於陣列中。" << std::endl;
    }

    return 0;
}