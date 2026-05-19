### 題目：[1845 – Seat Reservation Manager](https://leetcode.com/problems/seat-reservation-manager/description/)

#### 解題思路
設計一個系統來管理 $n$ 個座位的預訂狀況
- 要求：
    1. reserve()：永遠分配給使用者「當前最小編號」的可用座位
    2. unreserve(seatNumber)：將特定座位歸還，使其重新變回可用
- 核心策略：使用 最小堆疊 (Min-Heap)。因為我們需要頻繁地取出「最小」值，最小堆疊能在 $O(\log N)$ 的時間內完成取得與新增操作，遠優於使用陣列排序的效率

#### 關鍵邏輯：
1. 資料結構選擇：
    - priority_queue<int, vector<int>, greater<int>>：這是 C++ STL 提供的最小堆疊語法。與預設的最大堆疊不同，greater<int> 確保了堆疊頂端永遠是最小的整數
2. 座位初始化:
    - 建構函式將 1 到 n 的所有座位編號推入堆疊中，初始化費用為 $O(N \log N)$
3. reserve：
    - 直接取堆疊頂端的值並移除，該值即為當前最小編號
4. unreserve：
    - 將該編號重新推入堆疊，堆疊會自動進行平衡，確保下次 reserve() 時該座位能被正確取用

#### 模擬運算：
- Time Complexity：
    - reserve(): $O(\log N)$
    - unreserve(): $O(\log N)$
- Space Complexity：$O(N)$，用於儲存所有未預訂的座位編號

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - STL Min-Heap 的宣告：C++ 預設的 priority_queue 是最大堆疊，要實作最小堆疊必須補上 vector<int> 與 greater<int> 這兩個模板參數
    - 座位編號從 1 開始：務必確認迴圈是 1 到 n，這是開發管理系統時常見的邊界細節
    - 效率考量：若改用 std::set 也能達到同樣目的（set 內部是有序的，*s.begin() 即最小），但在存取速度上，堆疊在這種單純取最值的場景通常更輕量且快速
#### 總結 (Takeaway)
- 管理「最小可用資源」的 SOP：
    1. 初始化將所有可用資源放入最小堆疊
    2. 需分配時，直接 pop 堆疊頂端（保證最小）
    3. 資源回收時，直接 push 回堆疊