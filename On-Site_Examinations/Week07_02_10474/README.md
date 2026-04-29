### 題目：[UVa 10474 - Where is the Marble?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1415)

#### 解題思路
收集了 $N$ 顆寫有編號的大理石，將它們按照編號從小到大排好。接著有 $Q$ 次詢問，每次詢問某個編號的大理石是否在其中
- 目標：
    1. 如果找到，輸出該編號在「排序後」數列中的 第一個 索引位置
    2. 如果找不到，輸出 not found
- 限制：資料量較大，若每次詢問都從頭掃描一次 ($O(N)$)，總效率會變低，因此需要先排序後使用二分搜尋

#### 關鍵邏輯：
1. 資料預處理 (Sorting)：使用 std::sort 對大理石編號進行升序排列。排序是二分搜尋的基礎，時間複雜度為 $O(N \log N)$
2. 尋找邊界 (Lower Bound)：使用 C++ 內建的 std::lower_bound 進行搜尋
    - 特性：lower_bound 會回傳指向第一個「大於或等於」目標值的迭代器
    - 優點：這剛好符合題目要求「尋找第一個出現位置」的特性
3. 合法性驗證：
    - 檢查回傳的迭代器是否指向 end()（代表所有數都比目標小）
    - 檢查該位置的數值是否真的等於查詢值（因為 lower_bound 找到的可能是第一個比它大的數）
4. 座標轉換：
    - 計算索引：(it - marbles.begin() + 1)
    - 注意：題目要求的結果是 1-based index（從 1 開始算）

#### 模擬運算(Marbles: [2, 3, 5, 1], Query: 3 為例)：
- Step 1 (排序)：[1, 2, 3, 5]
- Step 2 (搜尋)：lower_bound 尋找 3
    - 找到第 3 個位置（索引 2，值為 3）
- Step 3 (輸出)：索引 2 轉換為 1-based 為 3
- 結果：3 found at 3
- Time Complexity：$O(N \log N + Q \log N)$。排序一次加上 $Q$ 次二分搜尋
- Space Complexity：$O(N)$。需要空間儲存所有大理石編號

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - lower_bound vs find：std::find 是線性搜尋 ($O(N)$)，而 std::lower_bound 在有序陣列中是二分搜尋 ($O(\log N)$)，效率天差地遠
    - 迭代器相減：在 C++ 中，兩個隨機存取迭代器相減（如 it - v.begin()）可以直接得到它們之間的距離（即索引值）
    - 多測資處理：利用 while (cin >> n >> q && (n != 0 || q != 0)) 是一種標準的解題寫法，確保在讀到 0 0 時正確終止程式

#### 總結 (Takeaway)
- 有序尋找問題 SOP：
    1. 將資料讀入後立即執行排序
    2. 利用二分搜尋（如 lower_bound）定位目標
    3. 驗證搜尋結果是否符合預期（是否等於目標值）
    4. 依題目要求轉換索引基準（0-based 或 1-based）
- 這種「先排序、後搜尋」的模式是處理大量靜態查詢問題的最優解