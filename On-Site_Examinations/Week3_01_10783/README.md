
# UVa 10783 - Odd Sum

## Problem Description

- 規則： 給你兩個數字 $i$ 和 $j$，請算出這兩個數字之間所有odd numbers的總和
- 目標： 正確讀取多筆測試資料，並印出結果
- Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1724)

## Learning Objectives
- [ ] Practice for loops.
- [ ] Check if a number is odd or even.
- [ ] Find and fix input bugs.

## Solution Approach

### Algorithm Logic
1. Read the number of test cases $T$.
2. Read the start number $i$ and end number $j$. 
3. If $i$ is an even number, add 1 to make it odd.
4. Use a for loop. Start from $i$ to $j$. Add 2 every time (x += 2).
5. Output the result with the correct format.

### Key Insights
- Smart Jump:I do not need to check every number. I find the first odd number, just add 2 (x += 2). This makes the program run faster!
- Input Trap:寫 cin 的時候一定要小心，變數之間必須用 >>。如果你不小心打成逗號 ,，電腦就會讀不到後面的變數。

## Code Structure
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, i, j;
    cin >> T;
    
    for (int Case = 1; Case <= T; Case++) {
        cin >> i >> j; 
        // 修正了之前在 j 前面誤打成 "," 的 bug (cin >> i, j; 是錯的)
        
        int sum = 0;
        
        // 如果 i 是偶數，加 1 變成奇數
        if (i % 2 == 0) {
            i += 1;
        }
        
        // 從第一個奇數開始，每次加 2
        for (int x = i; x <= j; x += 2) {
            sum += x;
        }
        
        cout << "Case " << Case << ": " << sum << "\n";
    }
    return 0;
}

```
[source code](./s1131420-UVa10783.cpp)

## Complexity Analysis
- **Time Complexity:**  $O(N)$
- **Space Complexity:**  $O(1)$

## Notes & Reflection
- 挑戰：最大的挑戰是一個小小的打字錯誤。我不小心把輸入打成逗號，導致 $j$ 沒有被正確讀取。
- 改進：目前的寫法已經很棒了。如果未來數字非常大，我們可以使用數學的「等差數列求和公式」來算，這樣就連迴圈都不用跑了。
- 學習： 仔細打字非常重要！即使是一個小小的逗號也會讓程式壞掉。