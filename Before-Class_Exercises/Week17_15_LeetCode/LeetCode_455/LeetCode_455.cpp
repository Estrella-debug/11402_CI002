#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // Sort both greed factors and cookie sizes
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int child_ptr = 0;
        int cookie_ptr = 0;
        
        // Greedily match cookies to children
        while (child_ptr < g.size() && cookie_ptr < s.size()) {
            if (s[cookie_ptr] >= g[child_ptr]) {
                child_ptr++; // This child is satisfied
            }
            cookie_ptr++; // Move to the next cookie regardless
        }
        
        return child_ptr;
    }
};
