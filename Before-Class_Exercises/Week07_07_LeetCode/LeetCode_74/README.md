### 題目：[74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)

#### 解題思路
在一個 $m \times n$ 的矩陣中尋找目標值 target
- 特性：
    1. 每行數字從左到右遞增
    2. 每行的第一個數字大於前一行的最後一個數字
- 策略：既然整個矩陣從左上到右下是完全遞增的，我們可以直接把它當成一個長度為 $m \times n$ 的排序陣列，使用一次 二元搜尋 即可完成

#### 關鍵邏輯：
1. 虛擬一維化 (Virtual 1D Array)：
    - 想像矩陣被「攤平」成一條直線
    - 左邊界 left = 0，右邊界 right = m * n - 1
2. 座標映射公式 (Index Mapping)：這是本題最核心的數學邏輯
    - 假設一維索引為 mid，則它在 $m \times n$ 矩陣（每行有 $n$ 個元素）中的位置為：
        - 列 (Row)：mid / n（看它包含幾個完整的橫列）
        - 行 (Col)：mid % n（剩下的餘數就是它在該列的位置）
3. 二元搜尋流程：
    - 計算 mid 並映射回矩陣取得 mid_val
    - 比較 mid_val 與 target：相等則回傳 true，太小則移動 left，太大則移動 right

#### 模擬運算($3 \times 4$ 矩陣，target = 3 為例)：
- 參數：$m=3, n=4$，總長度 $3 \times 4 = 12$
- 初始化：left = 0, right = 11
- 第一次迭代：
    - mid = 5
    - 映射座標：row = 5 / 4 = 1, col = 5 % 4 = 1
    - matrix[1][1] 為 11。11 > 3，right 變為 4
- 第二次迭代：
    - mid = 2
    - 映射座標：row = 2 / 4 = 0, col = 2 % 4 = 2
    - matrix[0][2] 為 5。5 > 3，right 變為 1
- 結果：最終會找到目標值 3
- Time Complexity：$O(\log(m \cdot n))$。這與標準二元搜尋的效率一致
- Space Complexity：$O(1)$。只使用了幾個整數變數

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 座標轉換技巧：學會如何用除法 / 和取餘數 % 在 1D 和 2D 座標間自由切換。這在處理影像處理或棋盤類題目時非常有用
    - 避免整數溢位：計算 mid 時使用 left + (right - left) / 2 而非 (left + right) / 2 是更安全的程式習慣
    - 邊界判斷：先檢查 matrix.empty() 是一種防禦性程式設計（Defensive Programming），可以避免讀取空資料造成的崩潰

#### 總結 (Takeaway)
- 有序矩陣搜尋 SOP：
    1. 判斷矩陣是否具備「全域遞增」的特性
    2. 若有，計算總長度 $m \times n$
    3. 執行二元搜尋，並在每次取出數值時利用公式轉換座標
- 這種做法比「先找哪一列，再找哪一行」的兩次搜尋法更簡潔且易於實作