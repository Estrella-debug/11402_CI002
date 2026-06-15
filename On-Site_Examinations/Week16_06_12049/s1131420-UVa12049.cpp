#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    map<int, int> count1;
    map<int, int> count2;
    
    // 讀取第一個陣列並計算頻率
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count1[x]++;
    }
    
    // 讀取第二個陣列並計算頻率
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        count2[x]++;
    }
    
    int deletions = 0;
    
    // 計算只在 map1 中，或在兩者出現次數不同的元素數量
    for (auto const& [key, val] : count1) {
        if (count2.find(key) != count2.end()) {
            deletions += abs(val - count2[key]);
        } else {
            deletions += val;
        }
    }
    
    // 計算只在 map2 中出現的元素數量
    for (auto const& [key, val] : count2) {
        if (count1.find(key) == count1.end()) {
            deletions += val;
        }
    }
    
    cout << deletions << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
