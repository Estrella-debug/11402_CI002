### 題目：[414. Third Maximum Number](https://leetcode.com/problems/third-maximum-number/description/)

#### 解題思路
給定一個非空整數陣列 nums，請找出其中 第三大 的數字
- 規則：
    1. 必須是 不重複 的前三大數
    2. 如果第三大的數字不存在，則回傳該陣列中 最大 的數字
- 策略：維護三個變數來記錄目前看到的第一大、第二大與第三大數

#### 關鍵邏輯：
1. 指標與狀態維護 (Pointer Tracking)：使用 long* 指標（max1, max2, max3）來初始化為 nullptr。這能有效區分「尚未找到數字」與「數字剛好是整數最小值（如 INT_MIN）」的情況
2. 去重處理 (Distinct Check)：在更新之前，先檢查當前數字是否已經存在於 max1, max2 或 max3 中。如果重複，則直接跳過
3. 階梯式更新 (Cascading Update)：
    - 如果 num 大於 max1：將 max2 給 max3，max1 給 max2，最後更新 max1
    - 如果 num 大於 max2：將 max2 給 max3，再更新 max2
    - 如果 num 大於 max3：直接更新 max3
4. 結果判定：最後檢查 max3 是否仍為空。若為空，表示不重複的數字少於三個，依題意回傳 *max1

#### 模擬運算([3, 2, 1]為例)：
- 數字 3：max1 = 3, max2 = null, max3 = null
- 數字 2：max1 = 3, max2 = 2, max3 = null
- 數字 1：max1 = 3, max2 = 2, max3 = 1
- 結果：max3 存在，回傳 1
- Time Complexity：$O(n)$。只需要掃描陣列一遍
- Space Complexity：$O(1)$。只使用了固定數量的指標變數

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 處理 INT_MIN 的陷阱：如果直接用 int 變數並初始化為 INT_MIN，當陣列中真的出現 INT_MIN 時會無法判斷。使用指標或 long 搭配 long_min 是更安全的做法
    - 指標動態配置：程式碼中使用 new long(num) 動態配置空間。雖然能解決邏輯問題，但在實務上需注意記憶體釋放（Memory Leak）的問題，或改用 std::optional (C++17)
    - 邏輯優先級：必須先檢查「是否重複」，再進行「大小比較」，否則會導致同一個數字被填入多個位置

#### 總結 (Takeaway)
- 尋找 Top-K 問題 SOP：
    1. 建立 K 個變數儲存狀態
    2. 遍歷資料，優先排除重複值
    3. 執行階梯式汰換（從最大開始比，贏了就依序往下推）
    4. 根據邊界條件（如 K 不存在時）回傳特定值
- 這種「階梯式更新」是處理固定數量極值問題最節省空間的做法