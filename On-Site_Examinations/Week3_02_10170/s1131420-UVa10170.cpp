#include <iostream>
using namespace std;

int main() {
    long long S, D, cnt; // 使用 long long 避開溢位陷阱
    while (cin >> S >> D) {// 讀取 S 和 D
        cnt = S;// 初始的 cnt 是 S，因為我們從 S 開始減去 D
        D -= S;// 首先減去 S，因為我們從 S 開始
        while (D > 0) {// 當 D 大於 0 時，繼續減去 cnt
            cnt++;// 每次增加 cnt，因為我們要減去的數字會逐漸增加
            D -= cnt;// 減去 cnt，直到 D 不再大於 0
        }
        cout << cnt << "\n";
    }
    return 0; 
}