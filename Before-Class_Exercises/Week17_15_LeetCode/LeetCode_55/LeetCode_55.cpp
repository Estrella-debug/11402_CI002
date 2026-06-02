#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int max_reach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is beyond our maximum reach, we are stuck
            if (i > max_reach) {
                return false;
            }
            
            // Update the furthest index we can safely reach
            max_reach = std::max(max_reach, i + nums[i]);
            
            // Early exit optimization: if we can already reach the last index, return true
            if (max_reach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
