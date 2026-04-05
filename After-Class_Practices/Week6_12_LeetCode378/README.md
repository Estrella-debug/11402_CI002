### 題目：[378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/)

#### 解題思路
在一個 $n \times n$ 的矩陣中找到第 $k$ 小的元素
- 特性：矩陣的每一行（Row）和每一列（Column）都已經按 升序 排列
- 核心挑戰：雖然行列有序，但整體並不是一維有序。如果直接展開排序需要 $O(n^2 \log n)$，使用優先權佇列需要 $O(k \log n)$。而本解法透過「猜數（二分值）」將效率提升至更高層次

#### 關鍵邏輯：
1. 對「值」進行二分搜尋 (Binary Search on Value)：
    - 搜尋範圍不是索引，而是數值：left 為左上角（最小值），right 為右下角（最大值）
    - 我們在 $[left, right]$ 中取一個中間值 mid，並計算矩陣中有多少個數「小於等於 mid」
2. 階梯式計數 (Stepwise Counting)：
    - 利用行列有序的特性，從 左下角 開始找：
        - 如果 matrix[row][col] <= mid：代表這一列從第 0 列到第 row 列都比 mid 小。我們累加計數 count += (row + 1)，並往 右 走一步
        - 如果 matrix[row][col] > mid：代表這個數太大了，往 上 走一步
3. 範圍縮減：
    - 如果 count < k：代表 mid 太小了，第 $k$ 小的數一定在右半部，left = mid + 1
    - 否則：mid 可能就是答案或比答案大，right = mid
#### 模擬運算：
- Range: left=1, right=15. 假設 mid = 8
- Count Less Equal (8):
    - 從左下角 12 開始：12 > 8 (上移) $\rightarrow$ 10 > 8 (上移) $\rightarrow$ 1 <= 8 (計數+1, 右移) $\rightarrow$ 5 <= 8 (計數+1, 右移) $\rightarrow$ 9 > 8 (上移)
    - 總數為 2。因為 2 < 8，所以 left = 9
- 最終收斂：當 left == right 時，該值即為第 $k$ 小的數
- Time Complexity：$O(n \cdot \log(Max - Min))$。每次計數需要 $O(n)$，二分搜尋次數由數值範圍決定
- Space Complexity：$O(1)$。不需要額外空間儲存矩陣複本

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 二分搜尋的變體：這不是對「索引」二分，而是對「答案可能存在的數值範圍」二分。這種技巧常用於「求第 K 個...」或「求最小化最大值」的問題
    - 矩陣搜尋路徑：從左下或右上出發，是利用 2D 排序矩陣單調性最有效率的方式，能將 $O(n^2)$ 的搜尋降至 $O(n)$
    - 收斂條件：使用 left < right 搭配 right = mid 是尋找「第一個滿足條件的值」的穩定寫法
#### 總結 (Takeaway)
- 有序矩陣第 K 小問題 SOP：
    1. 鎖定數值邊界（左上與右下）
    2. 二分猜測一個中間值
    3. 利用「左下出發步法」快速計算小於等於該值的數量
    4. 根據數量與 K 的關係縮減數值範圍
- 這種做法巧妙地避開了昂貴的排序，是處理海量有序矩陣資料時的首選演算法