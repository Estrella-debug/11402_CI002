### 題目：[658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/)

#### 解題思路
給定一個已排序的陣列 arr，找出其中最接近整數 x 的 k 個元素
- 規則：
    1. 距離 $|a - x| < |b - x|$ 時，元素 $a$ 更接近
    2. 如果距離相等 $|a - x| == |b - x|$，則數值較小的元素 $a$ 更接近
- 策略：先找到最接近 x 的起點，再向左右擴張直到湊滿 k 個數字

#### 關鍵邏輯：
1. 二元搜尋定位 (Find Starting Point)：使用 std::lower_bound 找到第一個大於等於 x 的位置
    - right：指向該位置（大於等於 x 的最小值）
    - left：指向 right - 1（小於 x 的最大值）
2. 向外擴張 (Expansion)：
    - 比較距離：比較 arr[left] 與 arr[right] 誰離 x 較近
    - 優先權處理：如果兩者距離相等，根據題目要求優先選擇較小的數字（即 left 側的元素）
    - 邊界保護：如果左邊或右邊已經到底了，則只能往另一邊繼續選
3. 範圍選取 (Slice)：
    - 當湊齊 k 個元素後，最後的範圍是 (left, right)（不包含邊界），因此結果為 [left + 1, right - 1]

#### 模擬運算(arr=[1,2,3,4,5], k=4, x=3為例)：
- 定位：lower_bound 找到 3。right = 2, left = 1
- 第一輪：比較 arr[1]=2 與 arr[2]=3 與 x=3 的距離。3 較近，right 變 3
- 第二輪：比較 arr[1]=2 與 arr[3]=4 與 x=3 的距離。距離相等 (1)，選較小的 2，left 變 0
- 持續進行：直到選滿 4 個數字
- Time Complexity：$O(\log n + k)$。二元搜尋需要 $\log n$，向外擴張需要 $k$ 次
- Space Complexity：$O(k)$。需要回傳一個含有 $k$ 個元素的結果向量

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - lower_bound 的應用：在已排序陣列中尋找插入點，它是效能最高的工具
    - 指標範圍定義：在 while 迴圈中，left 與 right 其實代表「下一個待檢查的候選人」
    - 區間選取：最後使用 vector 的迭代器建構子 vector<int>(begin, end) 來擷取子範圍，這比手動 for 迴圈更簡潔

#### 總結 (Takeaway)
- 尋找鄰近元素問題 SOP：
    1. 利用二元搜尋快速定位最接近的兩個數
    2. 使用雙指標從中心向左右擴散
    3. 嚴謹判斷距離與邊界條件
- 這種「中心擴散法」在處理有序資料的局部搜尋時非常高效