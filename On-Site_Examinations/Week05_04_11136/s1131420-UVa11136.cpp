#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        multiset<int> bills;
        long long total_cost = 0;
        
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int bill;
                cin >> bill;
                bills.insert(bill);
            }
            
            if (!bills.empty()) {
                // 找到最小和最大小票
                auto min_it = bills.begin();
                auto max_it = prev(bills.end());
                
                // 計算差值並累加
                total_cost += (*max_it - *min_it);
                
                // 刪除這兩張票
                bills.erase(min_it);
                bills.erase(max_it);
            }
        }
        cout << total_cost << endl;
    }
    return 0;
}
