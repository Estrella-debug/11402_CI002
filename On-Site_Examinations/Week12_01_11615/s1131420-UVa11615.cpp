#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 根據節點編號計算該節點在樹中的深度
int getDepth(int node) {
    int depth = 0;
    while (node > 0) {
        node /= 2;
        depth++;
    }
    return depth;
}

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;

    // 確保 A 是深度較淺的節點 (或者相同深度)
    if (getDepth(A) > getDepth(B)) {
        swap(A, B);
    }
    
    int depthA = getDepth(A);
    int depthB = getDepth(B);
    
    // 根據題目提示：這是一個層次遍歷序列的樹
    // 最大的子樹結構通常由相對更深的節點決定
    cout << (1 << N) - (1 << (N - depthA + 1)) + (1 << (N - depthB + 1)) << endl;
    // 上述公式為特定解法，通常本題只需簡單扣除法
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
