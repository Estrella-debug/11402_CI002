#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort intervals based on their end times in ascending order
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        // Keep track of the end time of the last accepted non-overlapping interval
        int prev_end = intervals[0][1];

        // Step 2: Iterate through the remaining intervals
        for (size_t i = 1; i < intervals.size(); ++i) {
            // If the current interval starts before the previous ends, there is an overlap
            if (intervals[i][0] < prev_end) {
                removals++; // Mark for removal
            } else {
                // No overlap, accept this interval and update the tracking end time
                prev_end = intervals[i][1];
            }
        }

        return removals;
    }
};
