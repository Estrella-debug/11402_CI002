#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequency of each number
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // 2. Use buckets where the index is the frequency
        // Max frequency possible is nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto const& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        // 3. Collect the top k elements from buckets (right to left)
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};
