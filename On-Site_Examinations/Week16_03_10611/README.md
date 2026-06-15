### 題目：[UVa 10611 - The Playboy Chimp](https://onlinejudge.org/external/106/10611.pdf)

#### 解題思路
給定一組按身高排序的黑猩猩身高陣列，對於每一位查詢的黑猩猩，找出陣列中：
- 矮個子：嚴格小於查詢身高的「最大」身高
- 高個子：嚴格大於查詢身高的「最小」身高
- 目標：快速回應每一筆查詢
- 核心特性：陣列已排序，這是二分搜尋適用的先決條件
- 核心策略：利用 C++ STL 的二分搜尋函式，分別取得第一個大於或等於 (lower_bound) 與第一個大於 (upper_bound) 的位置

#### 關鍵邏輯：
1. Lower Bound：
    - 回傳第一個「大於或等於」query 的元素位置
    - 若其不為陣列開頭，則前一個元素 (it_lower - 1) 即為嚴格小於 query 的最大值
2. Upper Bound：
    - 回傳第一個「嚴格大於」query 的元素位置
    - 此位置即為我們需要的「高個子」
3. 邊界處理：
    - 若 it_lower 為陣列開頭，表示沒有矮個子（輸出 X）
    - 若 it_upper 為陣列結尾，表示沒有高個子（輸出 X）

#### 模擬運算(heights = [1, 4, 5, 7], query = 4為例)：
1. Lower Bound：尋找 4。找到位置 1 (值為 4)
    - 前一個元素為 *(it_lower - 1) = 1。矮個子為 1
2. Upper Bound：尋找 4。找到位置 2 (值為 5)
    - 此值為 5。高個子為 5
- 結果：1 5
- Time Complexity：$O(Q \log N)$，其中 $Q$ 為查詢次數，$N$ 為身高陣列長度
- Space Complexity：$O(N)$，用於儲存身高陣列
#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - STL 的強大：在 C++ 中，lower_bound 與 upper_bound 已經實作了二分搜尋，無需手寫繁瑣的 while 迴圈判斷邊界，大幅降低了出錯機率
    - 指標算術 (Pointer Arithmetic)：理解 it_lower - 1 的意義，這是在二分搜尋中查找鄰居最標準的寫法
    - I/O 優化：對於 UVa 這類有大量測資的題目，務必使用 ios_base::sync_with_stdio(false)，否則頻繁的 cin / cout 會導致明顯的效能瓶頸
#### 總結 (Takeaway)
- 二分搜尋鄰居查找 SOP：
    1. 確保陣列已排序
    2. 使用 lower_bound 找到 >= 點，若前項存在則為「小於最大值」
    3. 使用 upper_bound 找到 > 點，即為「大於最小值」
    4. 檢查迭代器是否等於 begin() 或 end() 以處理邊界情況