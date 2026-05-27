#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 邊界條件：如果區間為空，直接回傳空陣列
        if (intervals.empty()) return {};

        // 1. 先將所有區間依照「左邊界」由小到大排序
        sort(intervals.begin(), intervals.end());
        
        // 2. 初始化目前合併區間的左右邊界 (已修正 r 的初始化 Bug)
        int l = intervals[0][0];
        int r = intervals[0][1];
        vector<vector<int>> ans;
        
        // 3. 遍歷每個區間進行合併
        for (auto& i : intervals) {
            if (i[0] > r) {
                // 情況 A：當前區間的左邊界大於目前合併區間的右邊界 -> 代表無法合併
                ans.push_back({l, r}); // 塞入上一個已經合併完的區間
                l = i[0];              // 開啟一個新的合併區間
                r = i[1];
            } else {
                // 情況 B：有重疊，更新右邊界為兩者較大值
                r = max(r, i[1]);
            }
        }
        // 4. 記得把最後一個留在手上的區間塞進答案中
        ans.push_back({l, r});
        return ans;
    }
};

int main() {
    Solution sol;

    // 測試範例 1: 正常重疊、包含
    // 輸入: [[1,3],[2,6],[8,10],[15,18]]
    // [1,3] 和 [2,6] 重疊，合併為 [1,6]
    // 預期輸出: [1,6], [8,10], [15,18]
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = sol.merge(intervals1);

    cout << "Example 1 Result: " << endl;
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << "\n\n";

    // 測試範例 2: 後者完全被前者包含
    // 輸入: [[1,4],[2,3]]
    // 預期輸出: [1,4]
    vector<vector<int>> intervals2 = {{1, 4}, {2, 3}};
    vector<vector<int>> result2 = sol.merge(intervals2);

    cout << "Example 2 Result: " << endl;
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}