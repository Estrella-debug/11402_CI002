#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 題目規定最大長度為 50，故陣列大小開 51
    vector<long long> dp(51, 0);
    
    // 初始化基礎狀態
    dp[1] = 1; // 長度為 1 有 1 種花樣
    dp[2] = 2; // 長度為 2 有 2 種花樣
    
    // 預先計算 3 到 50 的所有答案
    for (int i = 3; i <= 50; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    int n;
    // 持續讀取輸入，直到讀入 0 為止
    while (cin >> n && n != 0) {
        cout << dp[n] << "\n";
    }
    
    return 0;
}
