#include <iostream>
#include <vector>
#include <cmath>   // 為了使用 abs()
#include <algorithm>

using namespace std;

int main() {
    int n;
    // 持續讀取 n，直到輸入結束
    while (cin >> n) {
        // 如果 n 為 1，根據定義 1 個數字也算是 Jolly
        if (n == 1) {
            int temp;
            cin >> temp;
            cout << "Jolly" << endl;
            continue;
        }

        // 使用 vector 代替陣列，並初始化為 false (大小為 n)
        // 索引值 1 到 n-1 會用來記錄差值是否出現過
        vector<bool> appeared(n, false);
        
        int pre, now;
        cin >> pre; // 讀取第一個數

        for (int i = 1; i < n; i++) {
            cin >> now;
            int diff = abs(now - pre);
            
            // 重要修正：檢查 diff 是否在 1 到 n-1 的合法範圍內
            // 這樣可以避免像 d[abs(now-pre)] 導致的記憶體越界錯誤
            if (diff >= 1 && diff < n) {
                appeared[diff] = true;
            }
            
            pre = now; // 更新前一個數字
        }

        // 檢查 1 到 n-1 是否都出現過
        bool isJolly = true;
        for (int i = 1; i < n; i++) {
            if (!appeared[i]) {
                isJolly = false;
                break;
            }
        }

        if (isJolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}