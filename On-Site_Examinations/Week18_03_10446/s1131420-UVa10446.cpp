#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 使用 unsigned long long 避免大數溢位
unsigned long long memo[65][65];

unsigned long long solve(int n, int back) {
    // 邊界條件：依照題目設定，當 n <= 1 時，直接返回 1 次呼叫（本身被呼叫）
    if (n <= 0) return 1;
    if (n == 1) return 1;
    
    // 如果已經計算過，直接返回結果（記憶化優化）
    if (memo[n][back] != 0) {
        return memo[n][back];
    }
    
    // 初始化呼叫次數：當前這一層被呼叫算 1 次
    unsigned long long sum = 1;
    
    // 模擬題目中的迴圈：for(i=1; i<=back; i++) sum += trib(n-i, back);
    for (int i = 1; i <= back; ++i) {
        sum += solve(n - i, back);
    }
    
    // 記錄並返回
    return memo[n][back] = sum;
}

int main() {
    int n, back;
    int caseNum = 1;
    
    // 初始化記憶化陣列為 0
    memset(memo, 0, sizeof(memo));
    
    // 持續讀取輸入，題目規定當 n > 60 時終止程式
    while (cin >> n >> back && n <= 60) {
        // 如果輸入的 back 遇到負數，在 C++ 轉成 unsigned int 會變超大，
        // 但由於遞迴進入後 n-i 會快速小於 0 觸發邊界，保險起見直接帶入 solve 即可
        cout << "Case " << caseNum++ << ": " << solve(n, back) << "\n";
    }
    
    return 0;
}
