#include <iostream>
#include <algorithm>
#include <vector> // 引入 vector 標頭檔

using namespace std;

int main() {
    int T, N;
    
    // 讀取測試資料組數
    if (!(cin >> T)) return 0;

    while (T--) {
        // 讀取每組資料的元素個數
        if (!(cin >> N)) break;

        // 使用 vector 代替 int a[N]，以符合標準 C++ 規範並避免記憶體錯誤
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        int cnt = 0;
        /* 使用標準氣泡排序 (Bubble Sort) 邏輯：
           題目通常要求「相鄰」交換，氣泡排序每次比較 a[j] 與 a[j+1]。
           雖然你的原寫法結果相同，但氣泡排序更符合「火車軌道交換」的物理模型。
        */
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 1 - i; j++) {
                // 如果左邊比右邊大，則交換（確保相鄰交換）
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    cnt++; // 累計交換次數
                }
            }
        }

        // 輸出結果，格式需與題目完全一致
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }

    return 0;
}