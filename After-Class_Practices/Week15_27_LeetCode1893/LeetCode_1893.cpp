#include <vector>

class Solution {
public:
    bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right) {
        // Difference array to record shifts in coverage.
        // Given max range value is 50, an array of size 52 covers index 51.
        int diff[52] = {0};
        
        // 1. Populate the difference array
        for (const auto& r : ranges) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }
        
        // 2. Compute the prefix sum to re-evaluate coverage at each coordinate
        int current_coverage = 0;
        for (int i = 1; i <= right; ++i) {
            current_coverage += diff[i];
            
            // 3. If within target bounds and coverage drops to 0, return false
            if (i >= left && current_coverage <= 0) {
                return false;
            }
        }
        
        return true;
    }
};
