### 題目：[UVa 12250 - Language Detection](https://onlinejudge.org/external/122/12250.pdf)

#### 解題思路
給定幾個常見的招呼語與對應的語言，當輸入一個字串時，辨識該字串屬於哪種語言；若不在對照表中，則回傳 UNKNOWN
- 目標：根據輸入的招呼語判斷語言種類
- 核心特性：這是一個典型的「Key-Value」查找問題
- 核心策略：使用 std::map<string, string> 將招呼語（Key）映射至語言名稱（Value）

#### 關鍵邏輯：
1. 初始化字典：
    - 利用 std::map 將題目規定的對照表建立起來（如：HELLO 對應 ENGLISH）
2. 輸入處理：
    - 使用 while 迴圈讀取輸入，直到遇到結束符號 # 為止
    - 每一筆輸入都會計數 (n++)，並輸出對應的測試案例編號
3. 條件查找：
    - 使用 language.find(line) 檢查該輸入是否存在於 map 中
    - 若存在，輸出對應值；若不存在，輸出 UNKNOWN

#### 模擬運算(輸入 HELLO為例)：
1. 讀取：line = "HELLO"
2. 查找：在 language map 中搜尋 "HELLO"
3. 結果：找到，回傳對應的 "ENGLISH"
4. 輸出：Case 1: ENGLISH
- Time Complexity：$O(L \cdot \log N)$，其中 $N$ 是字典大小，$L$ 是字串長度（字串比較需要 $O(L)$）
- Space Complexity：$O(N \cdot L)$，用於儲存字典中的字串

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - Map 的便利性：使用 map 可以免去寫一大串 if-else 或 switch 的麻煩，讓程式碼更具擴充性
    - 結束條件判定：在 UVa 等平台上，務必清楚題目的結束條件（此題為 #），否則會導致讀取錯誤
    - 三元運算子的應用：程式碼中使用了 (condition) ? true : false 的三元運算子來簡化判斷，這在處理簡單的二選一輸出時非常方便

#### 總結 (Takeaway)
- 簡易語言偵測 SOP：
    1. 建立一個包含所有預設語言對照的資料結構 (如 map)
    2. 使用 while 迴圈讀取目標輸入直到結束條件
    3. 利用查找函式 (find 或 count) 確認輸入是否存在於資料庫中
    4. 若存在輸出對應內容，否則輸出預設錯誤訊息 (UNKNOWN)