#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int caseNum = 1;
    // 持續讀取輸入直到遇到 "end"
    while (cin >> s && s != "end") {
        vector<stack<char>> stacks;

        for (char c : s) {
            int bestStack = -1;
            char minTop = '{'; // 大於 'Z' 的字符，作為初始比較

            // 尋找符合條件的現有堆疊（Greedy）
            for (int i = 0; i < stacks.size(); ++i) {
                if (stacks[i].top() >= c && stacks[i].top() < minTop) {
                    minTop = stacks[i].top();
                    bestStack = i;
                }
            }

            // 如果找到適合的堆疊，放入；否則創建新堆疊
            if (bestStack != -1) {
                stacks[bestStack].push(c);
            } else {
                stack<char> ns;
                ns.push(c);
                stacks.push_back(ns);
            }
        }

        cout << "Case " << caseNum++ << ": " << stacks.size() << endl;
    }
    return 0;
}
