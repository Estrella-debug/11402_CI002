### 題目：[641. Design Circular Deque](https://leetcode.com/problems/design-circular-deque/description/)

#### 解題思路
設計一個支援雙端操作（在兩頭都能新增或刪除）的環形佇列
- 物理結構：使用固定大小的陣列
- 邏輯結構：利用「環形」特性，當 head 或 tail 移出陣列邊界時，自動繞回另一端
- 核心策略：維護兩個指標 head 與 tail。與普通佇列不同的是，雙端佇列需要處理「逆向移動」的邏輯（例如在隊首插入時，head 必須向左跨越邊界回到陣列末尾）

#### 關鍵邏輯：
1. 指針初始化設計：
    - 本程式碼採用 head = 0 與 tail = k - 1 的初始狀態。這種設計使得第一次 insertLast 會移動到索引 $0$，第一次 insertFront 會移動到索引 $k-1$，讓兩端的操作對稱展開
2. 環形移動公式：
    - 順向移動：(index + 1) % capacity（用於 deleteFront 或 insertLast）
    - 逆向移動：(index - 1 + capacity) % capacity（用於 insertFront 或 deleteLast）。加回 capacity 是為了防止 $0-1$ 變成負數，確保結果落在合法的索引範圍內
3. 狀態同步：
    - 使用 size 變數追蹤當前元素個數，不僅簡化了 isEmpty 與 isFull 的判定，也避免了傳統環形佇列需要「空出一格」來區分滿與空的複雜邏輯
4. 操作效率：
    - 所有操作均在常數時間 $O(1)$ 內完成，不涉及元素的搬移
#### 模擬運算(容量 3 為例)：
- 初始：head = 0, tail = 2, size = 0
- insertLast(1)：
    - tail = (2 + 1) % 3 = 0。buffer[0] = 1
- insertLast(2)：
    - tail = (0 + 1) % 3 = 1。buffer[1] = 2
- insertFront(3)：
    - head = (0 - 1 + 3) % 3 = 2。buffer[2] = 3
    - 此時 buffer 內容為 [1, 2, 3]，邏輯順序是 3 (head) -> 1 -> 2 (tail)
- Time Complexity：$O(1)$
- Space Complexity：$O(k)$，預分配固定大小的儲存空間

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 逆向取餘數技巧：學會了 (i - 1 + capacity) % capacity 這個萬用公式，它是實作環形結構逆向移動的標準寫法
    - 指針的對稱性：理解了 head 與 tail 在雙端操作下是如何「相向而行」或「背向而行」的
    - 靜態陣列優點：相較於鏈結串列實作，使用 vector 實作環形雙端佇列具有更好的快取友善性（Cache Friendliness）與更低的記憶體碎片風險
#### 總結 (Takeaway)
- 環形雙端佇列設計 SOP：
    1. 預分配固定大小的 buffer
    2. 定義 head 指向隊首元素，tail 指向隊尾元素
    3. 插入/刪除時，根據方向使用對應的取餘數公式更新指針
    4. 維護 size 計數器處理邊界判定
