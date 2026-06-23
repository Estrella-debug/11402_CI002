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
    // 最佳化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 題目測資 N 最大到 5000
    vector<string> fib(5001);
    
    // 初始化費氏數列基礎狀態
    fib[0] = "0";
    fib[1] = "1";
    
    // 預先建表：F(n) = F(n-1) + F(n-2)
    for (int i = 2; i <= 5000; ++i) {
        fib[i] = stringAdd(fib[i - 1], fib[i - 2]);
    }
    
    int n;
    // 持續讀取輸入直到 EOF
    while (cin >> n) {
        cout << "The Fibonacci number for " << n << " is " << fib[n] << "\n";
    }
    
    return 0;
}
