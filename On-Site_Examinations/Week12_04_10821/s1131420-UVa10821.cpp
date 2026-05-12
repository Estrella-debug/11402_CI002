#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 遞歸建立 BST 並前序輸出
void buildBST(int left, int right, int h, int caseNum) {
    if (left > right) return;
    if (left == right) {
        cout << left << (caseNum == -1 ? "" : " ");
        return;
    }

    // 為了保證高度，我們傾向於把更少的節點放在左邊，更多的放在右邊
    // 根節點位置選擇在能滿足高度條件的較右位置
    int numNodes = right - left + 1;
    
    // 計算當前高度 h 能容納的最大節點數，若 h 很大則不限制
    // 這裡使用簡化的邏輯：盡量讓左子樹少，右子樹多
    int root = left; // 默認根為 left，通常貪心取適當位置
    
    // 正確的 Greedy 策略：
    // 對於 N 個節點，h 高度，左子樹節點數應小於等於 2^(h-1) - 1
    // 因此根節點選擇在：left + max(0, numNodes - (1 << (h-1))) 左右
    
    int minLeftNodes = 0;
    if (h < 20) { // 2^20 > 10000, 避免溢出
        minLeftNodes = max(0, numNodes - ((1 << (h - 1)) - 1));
    }
    root = left + minLeftNodes;

    cout << root << " ";
    buildBST(left, root - 1, h - 1, -1);
    buildBST(root + 1, right, h - 1, -1);
}

int main() {
    int n, h;
    int caseCount = 1;
    while (cin >> n >> h && (n != 0 || h != 0)) {
        cout << "Case " << caseCount++ << ":";
        
        // 檢查是否無法建構
        if ((1 << h) - 1 < n) {
            cout << " Impossible" << endl;
        } else {
            // 前序遍歷輸出
            buildBST(1, n, h, 1);
            cout << endl;
        }
    }
    return 0;
}
