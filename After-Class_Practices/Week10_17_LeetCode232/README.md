### 題目：[232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/)

#### 解題思路
使用兩個堆疊來實作一個佇列，支援 push、pop、peek 與 empty 操作
- 核心衝突：堆疊會反轉資料順序，而佇列需要維持原始順序
- 策略：此程式碼採用了 「Push 成本較高 (Push-heavy)」 的策略。在每次 push 時，透過一個輔助堆疊將新元素強行安置在主堆疊的最底部，確保主堆疊的頂端永遠是「最早進入」的元素

#### 關鍵邏輯：
1. Double Inversion:
    - 當新元素 $x$ 要進入時，先將主堆疊 s 中的所有元素逐一彈出並壓入臨時堆疊 t
    - 此時，原本的元素順序被反轉了一次
    - 將 $x$ 放入空的 s 底端
    - 再將 t 中的元素搬回 s
    - 結果：$x$ 被壓在了所有舊元素的下方，而最舊的元素回到了 s.top()
2. 高效取值：
    - 由於 push 時已經處理好順序，pop() 與 peek() 只需要直接操作 s.top()，時間複雜度為 $O(1)$
3. 狀態判定：
    - 佇列是否為空，直接由主堆疊 s 是否為空來決定
#### 模擬運算(Push 1, 然後 Push 2為例)：
- Initial: s = []
- Push 1: 直接放入，s = [1] (Top 為 1)
- Push 2:
    1. 搬空 s：t = [1], s = []
    2. 放入新元素：s = [2]
    3. 搬回 t：s = [2, 1] (注意堆疊由底往上存，Top 為 1)
- Pop: 彈出 s.top()，得到 1。符合 FIFO 原則
- Time Complexity：
    - push: $O(n)$，因為每次都要搬動所有元素
    - pop/peek: $O(1)$
- Space Complexity：$O(n)$，需要額外的一個暫存堆疊

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 邏輯轉化：理解了如何透過兩個「負負得正」的反轉操作，將 LIFO 轉化為 FIFO
    - 效能權衡 (Trade-off)：此寫法優化了「讀取」的速度，但犧牲了「寫入」的效率。在 LeetCode 另一種常見解法中，可以優化為「攤還分析 $O(1)$」的 pop，但邏輯會稍微複雜一些（將搬動延後到 pop 時執行）
    - STL 容器熟練度：掌握了 std::stack 的 top(), push(), pop() 基本操作
#### 總結 (Takeaway)
- 堆疊轉佇列問題 SOP (Push-heavy 版)：
    1. 準備一個主堆疊與一個輔助堆疊
    2. push 時：搬空主堆疊 $\rightarrow$ 放入新成員 $\rightarrow$ 搬回成員
    3. pop 與 peek：直接對準主堆疊頂端
