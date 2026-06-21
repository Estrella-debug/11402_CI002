#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main() {
    // 儲存 3 個箱子各自的 B, G, C 數量
    vector<int> b(3), g(3), c(3);
    
    // 按照字母順序排列的 6 種箱子配置方式
    string names[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

    while (cin >> b[0] >> g[0] >> c[0] 
               >> b[1] >> g[1] >> c[1] 
               >> b[2] >> g[2] >> c[2]) {
        
        long long total_bottles = b[0]+g[0]+c[0] + b[1]+g[1]+c[1] + b[2]+g[2]+c[2];
        long long min_moves = LLONG_MAX;
        string best_ans = "";

        // 將對應關係設定為 0:B, 1:G, 2:C
        // 代表 {箱子1的顏色, 箱子2的顏色, 箱子3的顏色}
        int perm[6][3] = {
            {0, 1, 2}, // BCG
            {0, 2, 1}, // BGC
            {1, 0, 2}, // CBG
            {1, 2, 0}, // CGB
            {2, 0, 1}, // GBC
            {2, 1, 0}  // GCB
        };

        for (int i = 0; i < 6; i++) {
            int current_moves = 0;
            int color_idx[3];
            color_idx[0] = perm[i][0];
            color_idx[1] = perm[i][1];
            color_idx[2] = perm[i][2];

            // 計算移動次數：總瓶數 - (正確顏色箱子裡的瓶數)
            for (int j = 0; j < 3; j++) {
                if (color_idx[j] == 0) current_moves += b[j];
                else if (color_idx[j] == 1) current_moves += g[j];
                else if (color_idx[j] == 2) current_moves += c[j];
            }
            
            // 總移動數 = 總瓶數 - 保留在正確箱子的瓶數
            int moves = total_bottles - current_moves;

            if (moves < min_moves) {
                min_moves = moves;
                best_ans = names[i];
            }
        }

        cout << best_ans << " " << min_moves << endl;
    }

    return 0;
}
