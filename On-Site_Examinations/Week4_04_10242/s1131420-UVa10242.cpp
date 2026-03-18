#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    // 循環讀取直到EOF
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        double mx, my;
        // 找出重複的點，即兩條邊的交點
        if (x1 == x3 && y1 == y3) {
            mx = x2 + x4 - x1;
            my = y2 + y4 - y1;
        } else if (x1 == x4 && y1 == y4) {
            mx = x2 + x3 - x1;
            my = y2 + y3 - y1;
        } else if (x2 == x3 && y2 == y3) {
            mx = x1 + x4 - x2;
            my = y1 + y4 - y2;
        } else { // x2 == x4 && y2 == y4
            mx = x1 + x3 - x2;
            my = y1 + y3 - y2;
        }
        // 格式化輸出，保留三位小數
        printf("%.3f %.3f\n", mx, my);
    }
    return 0;
}
