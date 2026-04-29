#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// 檢查指定的容量是否可行
bool can_fit(const vector<int>& milk, int capacity, int max_containers) {
    int current_container = 1;
    int current_load = 0;
    
    for (int amount : milk) {
        if (amount > capacity) return false; // 單個容器大於容量

        if (current_load + amount > capacity) {
            current_container++;
            current_load = amount;
            if (current_container > max_containers) return false;
        } else {
            current_load += amount;
        }
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> milk(n);
        int max_milk = 0;
        long long sum_milk = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> milk[i];
            if (milk[i] > max_milk) max_milk = milk[i];
            sum_milk += milk[i];
        }
        
        // 二分搜尋答案
        long long low = max_milk;
        long long high = sum_milk;
        long long ans = sum_milk;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid == 0) { // 防止除以0，雖然題意通常不會
                low = mid + 1;
                continue;
            }
            
            if (can_fit(milk, mid, m)) {
                ans = mid;
                high = mid - 1; // 嘗試更小的容量
            } else {
                low = mid + 1; // 需要更大的容量
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
