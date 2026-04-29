
# UVa 10170 - The Hotel with Infinite Rooms

## Problem Description

- 規則： 旅館有無限多個房間。第一組客人有 $S$ 個人，他們會住 $S$ 天。接著下一組客人會有 $S+1$ 個人，住 $S+1$ 天，以此類推。
- 目標：給你第一組客人的數量 $S$ 和指定的某一天 $D$，請算出第 $D$ 天時，旅館裡住的那組客人總共有幾個人。
- Brief description of the problem here. [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111)

## Learning Objectives
- [ ] Use while loops to count days.
- [ ] Learn how to use large numbers (long long).
- [ ] Practice easy math logic.

## Solution Approach

### Algorithm Logic
1. Read the start size $S$ and day $D$. 
2. Set cnt = S. This is the current group size. 
3. Subtract $S$ from $D$.
4. Use a while loop. If $D > 0$, it means we need to find the next group.
5. In the loop, add 1 to cnt (next group size). Then, subtract cnt from $D$.
6. Output cnt when the loop ends.

### Key Insights
- Math Logic : 透過不斷從目標天數 $D$ 中扣除當前群組居住的天數。當 $D$ 被扣到小於或等於 $0$ 時，代表第 $D$ 天剛好落在「最後扣除的那組客人」居住的期間內。
- Corner Cases : 題目有特別標示 $D \le 10^{15}$。一般的 int 最大只能裝到約 $2 \times 10^9$，所以如果用 int 去存 $D$ 絕對會產生整數溢位 (Integer Overflow) 導致程式崩潰或算出負數。

## Code Structure
```cpp
#include <iostream>
using namespace std;

int main() {
    long long S, D, cnt; // 使用 long long 避開溢位陷阱
    while (cin >> S >> D) {// 讀取 S 和 D
        cnt = S;// 初始的 cnt 是 S，因為我們從 S 開始減去 D
        D -= S;// 首先減去 S，因為我們從 S 開始
        while (D > 0) {// 當 D 大於 0 時，繼續減去 cnt
            cnt++;// 每次增加 cnt，因為我們要減去的數字會逐漸增加
            D -= cnt;// 減去 cnt，直到 D 不再大於 0
        }
        cout << cnt << "\n";
    }
    return 0; 
}

```
[source code](./s1131420-UVa10170.cpp)

## Complexity Analysis
- **Time Complexity:**  O(?)
- **Space Complexity:**  $O(1)$

## Notes & Reflection
- 挑戰：The number $D$ is very big. If we use int, the code will get a Wrong Answer.
- 改進：We can also use math formula to find the answer without loops, but this way is easy to read.
- 學習： I learned how to subtract days one by one. I also remember to check the max size of numbers.