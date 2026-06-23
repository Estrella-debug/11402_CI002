#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 手寫字串大數加法
string stringAdd(const string& a, const string& b) {
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result += to_string(sum % 10);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // 題目測資 N 最大到 250，我們預先算好 0 到 250 的所有大數答案
    vector<string> dp(251);
    
    // 初始化基礎狀態
    dp[0] = "1";
    dp[1] = "1";
    
    // 預先建表：dp[i] = dp[i-1] + 2 * dp[i-2]
    for (int i = 2; i <= 250; ++i) {
        // 2 * dp[i-2] 相當於 dp[i-2] + dp[i-2]
        string two_times_prev2 = stringAdd(dp[i - 2], dp[i - 2]);
        dp[i] = stringAdd(dp[i - 1], two_times_prev2);
    }
    
    int n;
    // 持續讀取輸入直到 EOF
    while (cin >> n) {
        cout << dp[n] << "\n";
    }
    
    return 0;
}
