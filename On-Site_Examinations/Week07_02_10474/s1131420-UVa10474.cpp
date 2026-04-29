#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, caseNum = 1;
    // 循環讀取 n 和 q，直到兩者皆為 0
    while (cin >> n >> q && (n != 0 || q != 0)) {
        vector<int> marbles(n);
        for (int i = 0; i < n; ++i) {
            cin >> marbles[i];
        }

        // 1. 排序
        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum++ << ":" << endl;

        for (int i = 0; i < q; ++i) {
            int query;
            cin >> query;

            // 2. 使用 lower_bound 查找
            // lower_bound 返回指向第一個「大於或等於」query 的元素的迭代器
            auto it = lower_bound(marbles.begin(), marbles.end(), query);

            // 3. 檢查找到的元素是否為目標值
            if (it != marbles.end() && *it == query) {
                // 輸出為 1-based index
                cout << query << " found at " << (it - marbles.begin() + 1) << endl;
            } else {
                cout << query << " not found" << endl;
            }
        }
    }
    return 0;
}
