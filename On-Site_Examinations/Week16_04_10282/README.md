### 題目：[UVa 10282 - Babelfish](https://onlinejudge.org/external/102/10282.pdf)

#### 解題思路
給定一份字典，包含「母語」與「外星語」的對照，接著處理一系列外星語單字查詢
- 目標：若外星語存在於字典中，則輸出對應的母語；若查無此詞，輸出 eh
- 核心特性：這是一個單純的「鍵值對 (Key-Value)」儲存與查找問題
- 核心策略：使用 std::map<string, string> 建立以「外星語」為鍵 (Key)、以「母語」為值 (Value) 的索引系統，能在 $O(\log N)$ 的時間內完成查詢

#### 關鍵邏輯：
1. Parsing：
    - 字典輸入格式為 母語 外星語。我們使用 stringstream 來讀取並分離這兩個字串
    - 將 外星語 作為 key 存入 map，母語 作為 value
2. Lookup：
    - 使用 dict.find(input) 或 dict.count(input) 來判斷鍵值是否存在
    - 若找到，輸出 dict[input]；否則輸出 eh
3. 輸入結束判斷：
    - 字典部分與查詢部分由一個空行分隔，利用 getline 讀取並判斷是否為空行來切換讀取狀態

#### 模擬運算(字典 dog ogday為例)：
1. 建立映射：dict["ogday"] = "dog"
2. 查詢 ogday：查表發現存在，輸出 dog
3. 查詢 cat：查表發現不存在，輸出 eh
- Time Complexity：$O(L \cdot \log N)$，其中 $N$ 為字典詞彙量，$L$ 為字串平均長度（因為字串比較也需要時間）
- Space Complexity：$O(N \cdot L)$，用於儲存所有詞彙映射
#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - stringstream 的用途：在處理「同一行包含多個資料」的情況下，stringstream 是比 cin 更靈活且不容易造成格式錯誤的好工具
    - map 與 unordered_map：本題詞彙量通常不大，std::map (基於紅黑樹) 的 $O(\log N)$ 已經足夠。若追求極致效能，std::unordered_map (基於雜湊表) 可提供平均 $O(1)$ 的查詢速度
    - 空行處理：在競賽題目中，正確識別「分隔符號（如空行）」是避免讀取錯誤的關鍵
#### 總結 (Takeaway)
- 字典查找 SOP：
    1. 將輸入按空格拆解，建立 map 映射
    2. 以目標查詢值作為 Key 進行查找
    3. 利用 .find() 方法確認鍵值是否存在，避免直接存取不存在的 Key 導致產生不必要的預設值
    4. 根據結果決定輸出內容