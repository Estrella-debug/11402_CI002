#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int M, N, Q;
    if (!(cin >> M >> N >> Q)) return;
    vector<string> grid(M);
    for (int i = 0; i < M; ++i) cin >> grid[i];

    cout << M << " " << N << " " << Q << endl;

    while (Q--) {
        int r, c;
        cin >> r >> c;
        char centerChar = grid[r][c];
        int maxSide = 0;
        
        // 嘗試向外擴展
        for (int k = 0; ; ++k) {
            bool possible = true;
            // 檢查新的正方形邊界 (r-k, c-k) 到 (r+k, c+k)
            for (int i = r - k; i <= r + k; ++i) {
                for (int j = c - k; j <= c + k; ++j) {
                    // 檢查邊界條件與字元
                    if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] != centerChar) {
                        possible = false;
                        break;
                    }
                }
                if (!possible) break;
            }
            
            if (possible) {
                maxSide = 2 * k + 1;
            } else {
                break;
            }
        }
        cout << maxSide << endl;
    }
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
