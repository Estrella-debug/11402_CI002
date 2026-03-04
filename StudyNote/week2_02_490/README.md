
# UVa 490 - Rotating Sentences

## Problem Description

- 規則： 讀取多行句子，並將其順時針旋轉 90 度後輸出
- 目標： 第一行輸入的句子會變成輸出的最右邊那一列；最後一行輸入的句子會變成輸出的最左邊那一列，若句子長度不一，空缺的部分需以（Space）填補，維持矩陣排版
- Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=431)

## Learning Objectives
- [ ] Practice 2D array and string array manipulation.
- [ ] Understand coordinate transformation (Rotating a grid).
- [ ] Handle strings of varying lengths and proper character padding.

## Solution Approach

### Algorithm Logic
1. 宣告一個字串陣列 s 來儲存每一行輸入
2. 使用 getline(cin, s[col]) 逐行讀取，並用 col 紀錄總共輸入了幾行
3. 在讀取的同時，利用 max(row, (int)s[col].size()) 找出所有句子中最長的長度，存入 row
4. 輸出邏輯（雙層迴圈）
5. 每一列印完後換行

### Key Insights
- 矩陣轉換視角： 將變數直接設定為輸出後的 row 與 col，讓雙層迴圈的旋轉邏輯更直覺
- 精準空白補齊： 透過 if (i >= s[j].size()) 判斷，自動為較短的句子補上空白，確保排版整齊

## Code Structure
```cpp
#include<iostream>
#include<string>
using namespace std;

string s[113];// 題目限制最多 100 行，宣告 113 作為緩衝
int main() {
	cin.tie(0);// 優化輸入輸出速度
	int col = 0, row = 0;
	while (getline(cin, s[col])) {// 讀取每行輸入，直到 EOF
		row = max(row, (int)s[col].size());// 更新最大行長
		col++;// 更新行數
	}
	for (int i = 0; i < row; i++) {// 逐行輸出轉置後的結果
		for (int j = col - 1; j >= 0; j--) {// 從最後一行開始輸出
			if (i >= s[j].size()) cout << " ";// 如果當前行長不足，輸出空格
			else cout << s[j][i];// 否則輸出對應的字元
		}
		cout << "\n";// 每行結束後換行
	}
	
}

```
[source code](./s1131420-UVa490.cpp)

## Complexity Analysis
- **Time Complexity:**  $O(M \times N)$
- **Space Complexity:** $O(M \times N)$

## Notes & Reflection
- 挑戰： 雙層迴圈的邊界條件容易搞混
- 改進：加入 cin.tie(0) 搭配，確保在測資極大時程式不會因為 I/O 速度而 TLE
- 學習： 學習到不一定要建立一個真實的二維 char做矩陣旋轉，只要改變 **「讀取與印出的順序」**，就能達到旋轉的視覺效果