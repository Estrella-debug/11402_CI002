
# UVa 10035 - Primary Arithmetic

## Problem Description
Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=976)

## Learning Objectives
- [ ] Understand the Primary Arithmetic conjecture
- [ ] Implement iterative logic
- [ ] Practice input/output handling in C++

## Solution Approach

### Algorithm Logic
1. Read input values，若兩者皆為 0 則停止程式
2. 建立 carry 變數紀錄進位值，cnt 紀錄進位次數
3. 逐位加法：透過 % 10 取得當前最低位數，將兩數的位數與前一次的carry相加
4. 若和 >= 10，則令下一次的 carry 為 1，並將 cnt 加 1；否則 carry 歸 0
5. 將兩數分別 / 10 移至下一位，重覆3-4 直到兩數皆處理完
6. 依據 cnt值，依題目格式output
### Key Insights
- 進位遞進： 即使當前兩位數相加小於 10（例如 $5+4$），如果前一位有進位（carry=1），仍可能觸發新的進位（5+4+1=10）,**已經處理了這點**
- 輸出格式： 題目要求在 cnt == 0 時輸出 "No carry operation."，且**1 時使用單數 operation**，其餘使用**複數 operations**
- 邊界情況： 考慮位數不等長的數字（例如 $999$ 與 $1$），迴圈條件 (a1 > 0 || a2 > 0 )能確保所有位數都被處理到

## Code Structure
```cpp
#include<iostream>
using namespace std;
int main() {
	int a1, a2;
	while (cin >> a1 >> a2) {//輸入兩個值
		int carry = 0, cnt = 0;
		if (a1 == 0 && a2 == 0) break;//當a1,a2都為0時break
		while (a1 > 0 || a2 > 0) {//當其中一值大於0時繼續執行
			int tmp = a1 % 10 + a2 % 10 + carry;//將a1,a2的個位數相加再加上carry
			if (tmp >= 10) {//如果tmp>=10,carry為tmp/10的商，cnt加1
				carry = tmp / 10;
				cnt++;
			}
			else {
				carry = 0;//如果tmp<10,carry=0
			}
			a1 /= 10;//將a1,a2除以10,去掉個位數
			a2 /= 10;
		}
		if (cnt == 0)cout << "No carry operation.\n";
		else if (cnt == 1)cout << "1 carry operation.\n";
		else cout << cnt << " carry operations.\n";
	}
	return 0;
}
```
[source code](./s1131420_Uva10035.cpp)

## Complexity Analysis
- **Time Complexity:** O(?)
- **Space Complexity:** $O(1)$

## Notes & Reflection
- 挑戰： 一開始忘記 1 carry operation 是單數，沒考慮到連續進位（如 $999+1$ 會產生 3 次進位）的情況
- 改進： 目前使用 int input，雖然本題數據範圍在 unsigned int 以內，但若遇到超大整數（超過 10 位數），則須改用 string 讀取
- 學習： 練習如何利用餘數（%）與除法（/）拆解數字的每一位
