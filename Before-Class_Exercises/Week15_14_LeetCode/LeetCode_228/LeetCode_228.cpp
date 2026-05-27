#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            // Check for consecutive numbers
            // Note: i + 1 < n prevents out of bounds; nums[i] + 1 == nums[i+1] identifies range
            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
            }
            
            if (start != nums[i]) {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                result.push_back(to_string(start));
            }
        }
        return result;
    }
};
