#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        int q;
        cin >> q;
        while (q--) {
            int query;
            cin >> query;

            // 尋找嚴格大於 query 的第一個元素
            auto it_upper = upper_bound(heights.begin(), heights.end(), query);
            // 尋找大於或等於 query 的第一個元素
            auto it_lower = lower_bound(heights.begin(), heights.end(), query);

            // 處理矮個子 (嚴格小於)
            if (it_lower == heights.begin()) {
                cout << "X ";
            } else {
                // it_lower 是第一個 >= query 的元素，往前一個就是 < query 的最大值
                cout << *(it_lower - 1) << " ";
            }

            // 處理高個子 (嚴格大於)
            if (it_upper == heights.end()) {
                cout << "X\n";
            } else {
                cout << *it_upper << "\n";
            }
        }
    }

    return 0;
}
