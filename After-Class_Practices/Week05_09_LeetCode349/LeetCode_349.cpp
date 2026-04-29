#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        // 使用 unordered_set 存放結果，自動去重
        std::unordered_set<int> result_set;
        // 將 nums1 放入 unordered_set，時間複雜度 O(m)
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        
        // 遍歷 nums2，檢查是否在 nums1_set 中，時間複雜度 O(n)
        for (int num : nums2) {
            if (nums1_set.find(num) != nums1_set.end()) {
                result_set.insert(num);
            }
        }
        
        // 將結果從 set 轉換為 vector
        return std::vector<int>(result_set.begin(), result_set.end());
    }
};
