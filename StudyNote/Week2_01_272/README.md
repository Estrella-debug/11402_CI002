
# UVa 272 - TEX Quotes

## Problem Description

- 規則： 將文字中的雙引號 " 進行替換。遇到奇數次（第 1, 3, 5... 次）的雙引號時，替換為兩個反引號 ``；遇到偶數次（第 2, 4, 6... 次）時，替換為兩個單引號 ''
- 目標： 讀取所有輸入字串，將引號轉換成 TEX 格式後完整輸出，其餘字元保持不變
- Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208)

## Learning Objectives
- [ ] Practice string parsing and character replacement.
- [ ] Implement state tracking across multiple lines of input.
- [ ] Master reading input line by line using getline() in C++.

## Solution Approach

### Algorithm Logic
1. 使用 getline(cin, s) 逐行讀取字串，直到檔案結束
2. 建立一個計數器 cnt，用來記錄目前遇到了幾個雙引號
3. 使用 for 迴圈逐一檢查字串 s 中的每一個字元
4. 字元判斷：若當前字元不是雙引號 "，直接輸出該字元；若為雙引號，則依據 cnt 的奇偶性決定輸出 `` 或 ''，並將 cnt +1
```cpp
if (s[i] == '\"') {//當讀取到引號時
```
5. 每處理完一行字串，輸出一個換行符號 \n

### Key Insights
- 跨行狀態保留 (State Persistence)： 題目可能出現「上引號在第一行，下引號在第二行」的情況。因此，計數器 cnt 必須宣告在 main 迴圈之外（或是使用全域變數），絕不能在每次讀取新行時歸零
- 字元比對跳脫： 在 C++ 程式碼中要表示雙引號字元本身，必須使用跳脫字元 \"

## Code Structure
```cpp
#include<iostream>
#include<string>
using namespace std;

string s;
int cnt;//計數器預設為0
int main() {
	while (getline(cin, s)) {//使用getline讀取整行
		for (int i = 0; i < s.length(); i++) {//逐字元讀取
			if (s[i] == '\"') {//當讀取到引號時
				if (cnt % 2 == 0) {//當cnt為偶數時，輸出``
					cout << "``";
				}
				else {//當cnt為奇數時，輸出''
					cout << "''";
					//原在這打了cnt++ ,造成了上、下引號都使用了 `` 所以 WA;
				}
				cnt++;//經過訂正cnt++,放於此處才可分辨出上、下引號
			}
			else cout << s[i];//當讀取到非引號字元時，直接輸出
		}
		cout << "\n";//每行結束後換行
	}
    return 0;
}

```
[source code](./s1131420-UVa272.cpp)

## Complexity Analysis
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(L)$

## Notes & Reflection
- 挑戰： 找 bug 的過程，最初將 cnt++ 放在了 else 區塊內，導致上下引號無法正確交替，全部變成印出 ``，造成 WA，將其移到判斷式外後成功解決。
- 改進： 雖然目前的 getline 寫法很直覺，但也可以考慮不使用 string，改用 char c; while(cin >> noskipws >> c) 來達到逐字元讀取，這樣空間複雜度可以進一步降為 $O(1)$
- 學習： 學習到如何利用簡單的變數（如 cnt 的奇偶性）來製作一個Machine，控制程式在兩種不同的輸出邏輯間切換