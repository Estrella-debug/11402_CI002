#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, B, H, W;
    // 使用 while(cin >> ...) 處理多組測試資料
    while (cin >> N >> B >> H >> W) {
        int min_cost = B + 1; // 初始化最小成本為超過預算的值

        for (int i = 0; i < H; i++) {
            int price;
            cin >> price; // 讀取每人價格
            bool possible = false;
            for (int j = 0; j < W; j++) {
                int beds;
                cin >> beds; // 讀取每週床位
                if (beds >= N) {
                    possible = true;
                }
            }

            // 如果旅館可行且總費用在預算內，更新最小費用
            if (possible) {
                int total_cost = N * price;
                if (total_cost <= B) {
                    min_cost = min(min_cost, total_cost);
                }
            }
        }

        if (min_cost <= B) {
            cout << min_cost << endl;
        } else {
            cout << "stay home" << endl;
        }
    }
    return 0;
}
