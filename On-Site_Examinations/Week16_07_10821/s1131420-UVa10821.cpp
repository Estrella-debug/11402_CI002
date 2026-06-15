#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 遞迴建構並印出 BST
void buildBST(int l, int r, int h) {
    if (l > r) return;

    // 總節點數
    int n = r - l + 1;
    
    // 如果此子樹只有 1 個節點，直接印出
    if (n == 1) {
        cout << " " << l;
        return;
    }

    // 計算右子樹在 h-1 高度下最多能容納的節點數
    int max_right_nodes = (1 << (h - 1)) - 1;
    
    // 右子樹的節點數（不能超過此子樹剩餘的節點數與限制的節點數）
    int right_nodes = min(n - 1, max_right_nodes);
    
    // 根節點的位置 = 左半部總節點 + 左邊界
    int root = l + (n - 1 - right_nodes);

    cout << " " << root;

    // 遞迴建構左子樹與右子樹
    buildBST(l, root - 1, h - 1);
    buildBST(root + 1, r, h - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h;
    while (cin >> n >> h && (n != 0 || h != 0)) {
        // 如果高度太小，無法容納 n 個節點（滿二元樹的最大節點數為 2^h - 1）
        if (h < 31 && (1 << h) - 1 < n) {
            cout << "Impossible.\n";
        } else {
            cout << "To build this tree an inorder sequence can be:";
            buildBST(1, n, h);
            cout << "\n";
        }
    }
    return 0;
}
