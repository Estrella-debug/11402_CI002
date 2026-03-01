# UVa 100 - The 3n+1 Problem

## Problem Description

- 規則： 給予一正整數 $n$，若為偶數則 $n = n / 2$，若為奇數則 $n = 3n + 1$。重複此步驟直到 $n = 1$
- 目標： 在輸入的範圍 $[i, j]$ 之間，找出「循環長度」（Cycle Length）最大的數值，並輸出該最大長度
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36)

## Learning Objectives
- [ ] Understand the 3n+1 conjecture
- [ ] Implement iterative logic
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. Read input values
2. 處理輸入順序： 題目給的 $x, y$ 不一定是由小到大，因此需先記錄原始順序（用於輸出），再找出 $min(x, y)$ 與 $max(x, y)$ 作為迴圈範圍
3. Output the result

### Key Insights
- Note any important observations
- Edge cases to consider
- Optimization techniques used

## Code Structure
```cpp
#include <iostream>
using namespace std;
int main() {
	int x, y;
	while (cin >> x >> y) {//輸入x和y，直到EOF
		int max_ = 0;
		for (int n = min(x, y); n <= max(x, y); n++) {//從x和y中較小的數開始，直到較大的數
			int n1 = n, count = 1;//
			while (n1 != 1) {//n=1跳出
				if (n1 % 2 != 0)//n1為奇數
					n1 = 3 * n1 + 1;//n1為偶數
				else n1 /= 2;
				count++;
			}
			max_ = max(max_, count);//更新最大值
		}
		cout << x << " " << y << " " << max_ << endl;
	}
    return 0;
}
```
[source code](./s1131420_Uva100.cpp)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** $O(1)$

## Notes & Reflection
- 挑戰： 處理輸入順序(輸入100 10 而非10 100)
- 改進： 目前是暴力法，若範圍更大，會造成整數溢位
- 學習： 學習到如何處理不確定長度的輸入 while(cin >> x >> y)
