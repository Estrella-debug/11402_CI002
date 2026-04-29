### 題目：[33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

#### 解題思路
在一個經過「旋轉」的排序陣列 nums 中尋找目標值 target
- 旋轉定義：例如 [0, 1, 2, 4, 5, 6, 7] 可能在索引 3 處旋轉變成 [4, 5, 6, 7, 0, 1, 2]
- 限制：必須實作時間複雜度為 $O(\log n)$ 的演算法
- 核心策略：雖然陣列被旋轉，但如果我們將其切半，左半部或右半部一定有一個是完全有序的

#### 關鍵邏輯：
1. 二元搜尋基礎：同樣設定 left 與 right 指標
2. 判斷哪邊有序 (Check Sorted Side)：
    - 如果 nums[left] <= nums[mid]，代表從 left 到 mid 是 左半部有序
    - 否則，代表從 mid 到 right 是 右半部有序
3. 縮減搜尋範圍：
    - 左半部有序時：檢查 target 是否落在這個區間內（nums[left] <= target < nums[mid]）
        - 若在區間內，往左找 (right = mid - 1)
        - 若不在區間內，往右找 (left = mid + 1)
    - 右半部有序時：同樣檢查 target 是否落在該區間內（nums[mid] < target <= nums[right]）
        - 若在區間內，往右找 (left = mid + 1)
        - 若不在區間內，往左找 (right = mid - 1)
#### 模擬運算(nums = [4, 5, 6, 7, 0, 1, 2], target = 0 為例)：
- 第一次迭代：left = 0, right = 6。mid = 3 (值為 7)
    - nums[0] (4) <= nums[3] (7) $\rightarrow$ 左半部有序
    - 檢查目標 0：0 不在 [4, 7] 之間
    - 往右半部找：left = 4
- 第二次迭代：left = 4, right = 6。mid = 5 (值為 1)
    - nums[4] (0) <= nums[5] (1) $\rightarrow$ 左半部有序
    - 檢查目標 0：0 剛好在 [0, 1) 區間內
    - 往左半部找：right = 4
- 第三次迭代：mid = 4 (值為 0)。匹配成功！ 回傳索引 4
- Time Complexity：$O(\log n)$。雖然多了有序判斷，但每次依然能排除一半的元素
- Space Complexity：$O(1)$

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 分段有序性：這是解決旋轉陣列問題的「萬用鑰匙」。只要是從排序陣列旋轉來的，切一刀下去，必有一邊是乖乖排好的
    - 邊界條件的等號：在判斷有序（nums[left] <= nums[mid]）以及範圍（nums[left] <= target）時，等號的處理非常關鍵，否則在元素很少時會出錯
    - 二元搜尋的強大：即使資料不是完美的線性遞增，只要具備某種「區間單調性」，二元搜尋就能派上用場
#### 總結 (Takeaway)
- 旋轉陣列搜尋 SOP：
    1. 定出中點 mid
    2. 先找出哪一半是正常的（有序的）
    3. 看目標是否在正常的範圍內
    4. 如果在，就在那邊搜尋；如果不在，去另一邊「不正常」的地方搜尋
