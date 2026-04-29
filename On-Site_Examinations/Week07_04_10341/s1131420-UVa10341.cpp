#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 定義方程式
double p, q, r, s, t, u;
double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
    // 處理多筆測資
    while (cin >> p >> q >> r >> s >> t >> u) {
        // 檢查邊界值，確保根在範圍內
        if (f(0) * f(1) > 1e-9) {
            cout << "No solution" << endl;
            continue;
        }

        // 二分搜尋
        double low = 0.0, high = 1.0;
        for (int i = 0; i < 100; ++i) { // 迭代 100 次以達到高精度
            double mid = (low + high) / 2.0;
            if (f(mid) > 0) {
                // 如果 f(x) 是單調遞減的，f(mid)>0 意味著根在右邊
                // 原題函數 f(x) 在 [0,1] 通常遞減，若 f(0)>0 且 f(1)<0
                low = mid;
            } else {
                high = mid;
            }
        }
        
        // 輸出結果，保留 4 位小數
        cout << fixed << setprecision(4) << low << endl;
    }
    return 0;
}
