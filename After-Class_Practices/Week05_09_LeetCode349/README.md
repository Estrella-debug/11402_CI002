### 題目：[349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/)

#### 解題思路
給定兩個陣列 nums1 和 nums2，找出它們的 交集
- 規則：結果中的每個元素必須是 唯一 的
- 核心挑戰：如何快速判斷一個數字是否同時存在於兩個陣列中，並確保輸出結果沒有重複數字。

#### 關鍵邏輯：
1. 快速查找 (The Power of Hash Set)：使用 std::unordered_set<int>
    - 去重：set 容器本身就不允許重複元素
    - 效能：unordered_set 基於雜湊表 (Hash Table)，其查找與插入的平均時間複雜度為 $O(1)$
2. 分段處理：
    - 第一步：將 nums1 的所有元素放入 nums1_set。此時 nums1 中的重複數字會自動消失
    - 第二步：遍歷 nums2，利用 find() 檢查每個數字是否出現在 nums1_set 中
    - 第三步：如果存在，將其放入 result_set（再次確保結果去重）
3. 格式轉換：最後將 result_set 轉回 vector<int> 作為最終回傳值

#### 模擬運算(nums1 = [1, 2, 2, 1], nums2 = [2, 2] 為例)：
- 步驟 1：將 nums1 轉為 set $\rightarrow$ {1, 2}
- 步驟 2：檢查 nums2 中的第一個 2 $\rightarrow$ 存在於 {1, 2}，加入結果集 {2}
- 步驟 3：檢查 nums2 中的第二個 2 $\rightarrow$ 存在於 {1, 2}，加入結果集 {2} (集合不變)
- 結果：輸出 [2]
- Time Complexity：$O(m + n)$。$m$ 是 nums1 長度，$n$ 是 nums2 長度
- Space Complexity：$O(m)$。需要額外空間儲存第一個陣列的集合

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - Set vs Unordered_Set：如果不需要結果按順序排列，使用 unordered_set 速度會比 set (紅黑樹) 快得多
    - 建構子技巧：std::unordered_set<int> nums1_set(nums1.begin(), nums1.end()); 這種利用迭代器範圍的初始化方式非常簡潔
    - 查找語法：find(num) != end() 是 C++ 判斷元素是否存在於集合中的標準寫法

#### 總結 (Takeaway)
- 陣列交集問題 SOP：
    1. 將其中一個陣列存入雜湊集合 (Hash Set)
    2. 檢查另一個陣列的元素是否存在於該集合
    3. 將重複出現的元素存入另一個結果集合以達成去重
- 雜湊表是處理「是否存在」與「去重」問題最強大的武器