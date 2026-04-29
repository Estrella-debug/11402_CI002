#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string i : tokens) {
            // 如果不是運算符號，就是數字，將其轉為整數並推入堆疊
            if (i != "+" && i != "-" && i != "*" && i != "/") {
                s.push(stoi(i));
                continue;
            }
            
            // 遇到運算符號，取出堆疊頂端的兩個數字
            // 注意：先彈出的是右操作數 (x)，後彈出的是左操作數 (y)
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            
            if (i == "+") {
                s.push(y + x);
            } else if (i == "-") {
                s.push(y - x);
            } else if (i == "*") {
                s.push(y * x);
            } else {
                s.push(y / x); // C++ 預設整數除法會向零取整
            }
        }
        // 最後堆疊中剩下的唯一數字就是計算結果
        return s.top();
    }
};

int main() {
    Solution sol;

    // 測試範例 1: (2 + 1) * 3
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Example 1 Result: " << sol.evalRPN(tokens1) << " (Expected: 9)" << endl;

    // 測試範例 2: 4 + (13 / 5)
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Example 2 Result: " << sol.evalRPN(tokens2) << " (Expected: 6)" << endl;

    // 測試範例 3: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Example 3 Result: " << sol.evalRPN(tokens3) << " (Expected: 22)" << endl;

    return 0;
}