### 題目：[704. Binary Search](https://leetcode.com/problems/binary-search/description/)

#### 解題思路
在一個 已排序（Sorted） 的整數陣列 nums 中，尋找目標值 target 的索引位置
- 核心前提：二分搜尋只能用在「有序」的資料上
- 策略：每次都檢查中間的數字，如果中間的數不是目標，就根據大小關係直接排除掉「一半」的搜尋範圍

#### 關鍵邏輯：
1. 定義邊界 (Range)：設定 left = 0 和 right = nums.size() - 1，代表搜尋範圍是包含左右邊界的閉區間 [left, right]
2. 計算中點 (Middle)：
    - 避坑技巧：使用 left + (right - left) / 2 來計算 mid。這比 (left + right) / 2 更安全，可以防止當 left 和 right 很大時相加產生的 整數溢位 (Overflow)
3. 三種判斷：
    - nums[mid] == target：運氣很好，直接找到並回傳
    - nums[mid] < target：目標比較大，一定在右半邊，所以將 left 移到 mid + 1
    - nums[mid] > target：目標比較小，一定在左半邊，所以將 right 移到 mid - 1
4. 結束條件：當 left > right 時，代表搜尋範圍已經耗盡仍未找到，回傳 -1

#### 模擬運算(nums = [-1, 0, 3, 5, 9, 12], target = 9 為例)：
- 第一次迭代：left=0, right=5。mid = 2 (值是 3)
    - 3 < 9，目標在右邊。left 變為 3
- 第二次迭代：left=3, right=5。mid = 4 (值是 9)
    - 9 == 9，找到目標！ 回傳索引 4
- Time Complexity：$O(\log n)$。每次都砍掉一半的資料，效率極高
- Space Complexity：$O(1)$。只用了幾個整數變數儲存索引

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 溢位意識：即使是簡單的加法，在處理大數據（如索引值接近 $2^{31}$）時也要考慮 overflow 的風險
    - 區間定義的嚴謹性：如果 right 初始化為 nums.size()（左閉右開），則 while 條件應改為 left < right，且 right 應更新為 mid。這套程式碼使用的是最直覺的 雙閉區間 寫法
    - 效率的差距：比起從頭到尾掃描的線性搜尋 ($O(n)$)，二分搜尋 ($O(\log n)$) 在資料量達百萬級時速度快了數萬倍

#### 總結 (Takeaway)
- 二分搜尋問題 SOP：
    1. 確認陣列是否已排序
    2. 設定左右邊界指標
    3. 在迴圈中計算安全的中點 mid
    4. 根據大小關係移動 left 或 right
- 這是所有進階搜尋演算法（如二分搜尋樹、B-Tree）的核心邏輯，必須非常熟練