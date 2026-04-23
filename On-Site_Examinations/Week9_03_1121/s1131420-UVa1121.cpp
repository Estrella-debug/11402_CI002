#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    long long S;
    // 讀取N和S，使用while(cin >> N >> S)來處理多組測試數據
    while (cin >> N >> S) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }

        int left = 0;
        long long current_sum = 0;
        int min_len = N + 1; // 初始化為一個不可能的長度

        for (int right = 0; right < N; ++right) {
            current_sum += nums[right];

            // 當前窗口總和不小於S時，嘗試縮小視窗
            while (current_sum >= S) {
                min_len = min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        // 如果min_len沒被更新，說明找不到滿足條件的子序列
        if (min_len == N + 1) {
            cout << 0 << endl;
        } else {
            cout << min_len << endl;
        }
    }
}

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
