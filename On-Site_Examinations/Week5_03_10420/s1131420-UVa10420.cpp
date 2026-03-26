#include <iostream>
#include <sstream> // 為了使用 stringstream
#include <map>     // 為了使用 map 容器
using namespace std;

int main() {
    int n;
    // 讀取接下來總共有幾行資料
    cin >> n; 

    // 宣告一個 map，key 為字串 (單詞)，value 為整數 (出現次數)
    // map 會自動依照 key 的字典順序進行排序
    map <string, int> mp; 

    string s;
    // 重要：消耗掉讀取 n 之後留在緩衝區的換行符號，避免影響後續 getline
    getline(cin, s); 

    // 執行 n 次迴圈，每次讀取一行
    while (n--) {
        getline(cin, s);      // 讀取整行字串
        stringstream ss(s);   // 將該行字串放入 stringstream 流中
        ss >> s;              // 從流中提取第一個單詞 (會自動忽略前導空格)
        mp[s]++;              // 將該單詞在 map 中的計數加 1
    }

    // 使用範圍迴圈 (range-based for loop) 遍歷 map
    // i.first 是鍵 (單詞)，i.second 是值 (次數)
    for (auto i : mp) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}