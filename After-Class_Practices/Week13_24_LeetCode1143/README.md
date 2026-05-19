### 題目：[1143 - Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/)

#### 解題思路
給定兩個字串 text1 與 text2，找出它們的最長共同子序列。子序列是指一個字串在不改變順序的情況下，刪除部分字元（或不刪除）後形成的新字串
- 目標：求出 LCS 的長度
- 核心特性：
    1. 若兩個字串結尾字元相同 text1[i-1] == text2[j-1]，則 LCS 長度為「去掉兩者末位後的 LCS 長度 + 1」
    2. 若不同，則 LCS 長度為「去掉 text1 末位」與「去掉 text2 末位」這兩種情況中的最大值
- 核心策略：使用二維 DP 表格 dp[m+1][n+1]，其中 dp[i][j] 代表 text1 前 i 個字元與 text2 前 j 個字元的最長共同子序列長度
#### 關鍵邏輯：
1. 狀態定義：
    - dp[i][j]：代表 text1[0...i-1] 與 text2[0...j-1] 的 LCS 長度
2. Transition Formula:
    - 匹配成功：if (text1[i-1] == text2[j-1])
dp[i][j] = 1 + dp[i-1][j-1]
3. 邊界條件：
    - 當 i=0 或 j=0 時，表示有一個字串為空，LCS 長度必為 0。透過 vector 初始化為 0 可自動滿足

#### 模擬運算(text1 = "abc", text2 = "ac"為例)：
- Initialization：建立 4x3 的 dp 表，初始全為 0
- 執行計算：
    - i=1 (a), j=1 (a)：匹配，dp[1][1] = dp[0][0] + 1 = 1
    - i=2 (b), j=2 (c)：不匹配，dp[2][2] = max(dp[1][2], dp[2][1]) = 1
    - i=3 (c), j=2 (c)：匹配，dp[3][2] = dp[2][1] + 1 = 1 + 1 = 2
- 結果：最終結果存於 dp[3][2] 為 2
- Time Complexity：$O(m \times n)$，其中 $m$ 和 $n$ 分別為兩個字串的長度
- Space Complexity：$O(m \times n)$，用於儲存 DP 狀態表
#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 索引對齊：DP 表大小為 (m+1) x (n+1)，需謹記 dp[i][j] 對應字串的 i-1 和 j-1 位置
    - 空間優化潛力：LCS 的狀態更新只依賴於當前行與上一行，在記憶體嚴苛場景下，可將空間優化至 $O(\min(m, n))$
    - 直觀的狀態轉移：相比於純遞迴，此迭代法完美避開了重複計算的問題，大幅提升了效能
#### 總結 (Takeaway)
- LCS 構造 SOP：
    1. 建立 (m+1) x (n+1) 的 DP 表格
    2. 將邊界（第 0 列與第 0 行）設為 0
    3. 兩層迴圈遞迴填充狀態
    4. 相符則左上方加一，不相符則取上方與左方的最大值