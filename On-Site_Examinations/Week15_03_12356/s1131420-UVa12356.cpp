#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 加速 I/O 操作，避免 Time Limit Exceeded
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S, B;
    while (cin >> S >> B && (S != 0 || B != 0)) {
        vector<int> left(S + 2);
        vector<int> right(S + 2);

        // 初始化每個士兵左右相鄰的編號
        for (int i = 1; i <= S; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        
        // 邊界條件設定：最左和最右的士兵外沒有人
        left[1] = 0;
        right[S] = 0;

        for (int i = 0; i < B; ++i) {
            int L, R;
            cin >> L >> R;

            // 1. 處理左邊界
            if (left[L] != 0) {
                right[left[L]] = right[R];
                cout << left[L] << " ";
            } else {
                cout << "* ";
            }

            // 2. 處理右邊界
            if (right[R] != 0) {
                left[right[R]] = left[L];
                cout << right[R] << "\n";
            } else {
                cout << "*\n";
            }
        }
        cout << "-\n"; // 輸出每組測試資料結束的分隔符號
    }

    return 0;
}
