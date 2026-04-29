#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t, n;
    if (!(cin >> t)) return 0; // 確保讀取成功

    while (t--) {
        int pos = 0; // 機器人的位置
        cin >> n;
        
        vector<int> history(n); // 記錄每一步的位移量
        string s;

        for (int i = 0; i < n; i++) {
            cin >> s; // 先讀取第一個單字 (LEFT, RIGHT, 或 SAME)
            
            if (s == "LEFT") {
                history[i] = -1;
            } 
            else if (s == "RIGHT") {
                history[i] = 1;
            } 
            else {
                // 如果是 SAME，後面還跟著 "AS" 和數字 X
                string temp;
                int index;
                cin >> temp >> index; // 讀掉 "AS" 並取得數字 X
                history[i] = history[index - 1];
            }
            pos += history[i];
        }
        cout << pos << endl;
    }
    return 0;
}