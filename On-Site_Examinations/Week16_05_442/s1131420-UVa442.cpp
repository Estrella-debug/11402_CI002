#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

// 定義矩陣結構
struct Matrix {
    int rows;
    int cols;
};

int main() {
    // 關閉同步加速 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<char, Matrix> matrices;

    // 讀取所有矩陣的名稱與維度
    for (int i = 0; i < n; ++i) {
        char name;
        int r, c;
        cin >> name >> r >> c;
        matrices[name] = {r, c};
    }

    string expr;
    // 逐行讀取運算式
    while (cin >> expr) {
        stack<Matrix> s;
        long long total_mult = 0; // 計算總乘法次數
        bool error = false;       // 標記矩陣是否可相乘

        for (char c : expr) {
            if (isalpha(c)) {
                // 如果是字母，直接放入 stack 中
                s.push(matrices[c]);
            } else if (c == ')') {
                // 如果是右括號，從 stack 中取出兩個矩陣計算
                Matrix m2 = s.top(); s.pop();
                Matrix m1 = s.top(); s.pop();

                // 檢查是否符合矩陣相乘規則 (m1 的行數須等於 m2 的列數)
                if (m1.cols != m2.rows) {
                    error = true;
                    break;
                }

                // 計算乘法次數：r1 * c1 * c2
                total_mult += m1.rows * m1.cols * m2.cols;

                // 將相乘後的新矩陣放入 stack (維度為 m1.rows x m2.cols)
                s.push({m1.rows, m2.cols});
            }
            // 若為左括號 '(' 則不做任何處理
        }

        // 輸出結果
        if (error) {
            cout << "error\n";
        } else {
            cout << total_mult << "\n";
        }
    }

    return 0;
}
