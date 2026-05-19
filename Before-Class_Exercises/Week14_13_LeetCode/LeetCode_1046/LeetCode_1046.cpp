#include <iostream>
#include <vector>
#include <queue>
#include <cmath> // for abs

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // C++ 預設的 priority_queue 是最大堆疊 (Max-Heap)，數字最大的在最上面
        priority_queue<int> pq;
        for (int i : stones) {
            pq.push(i);
        }
        
        // 只要還有至少兩顆石頭，就繼續碰撞
        while (pq.size() > 1) {
            int x = pq.top(); // 第一重的石頭
            pq.pop();
            int y = pq.top(); // 第二重的石頭
            pq.pop();
            
            // 如果兩顆石頭重量相同，兩顆都完全碎裂，不需要放回堆疊
            if ((x - y) == 0) {
                continue;
            }
            // 如果重量不同，將碰撞後剩下的重量放回堆疊
            pq.push(abs(x - y));
        }
        
        // 如果最後所有石頭都碎了，回傳 0
        if (pq.empty()) {
            return 0;
        }
        // 否則回傳最後剩下那一顆石頭的重量
        return pq.top();
    }
};

int main() {
    Solution sol;
    
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    cout << "Example 1 Result: " << sol.lastStoneWeight(stones1) << " (Expected: 1)" << endl;

    // 測試範例 2: 所有石頭剛好完全抵消
    vector<int> stones2 = {2, 2};
    cout << "Example 2 Result: " << sol.lastStoneWeight(stones2) << " (Expected: 0)" << endl;

    // 測試範例 3: 只有一顆石頭
    vector<int> stones3 = {5};
    cout << "Example 3 Result: " << sol.lastStoneWeight(stones3) << " (Expected: 5)" << endl;

    return 0;
}