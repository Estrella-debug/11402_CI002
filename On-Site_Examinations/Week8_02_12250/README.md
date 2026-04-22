### 題目：[UVa 12250 - Language Detection](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3402)

#### 解題思路
給定一個代表「你好」的單字，判斷該單字屬於哪種語言
- 語言清單：
    - HELLO $\rightarrow$ ENGLISH
    - HOLA $\rightarrow$ SPANISH
    - HALLO $\rightarrow$ GERMAN
    - BONJOUR $\rightarrow$ FRENCH
    - CIAO $\rightarrow$ ITALIAN
    - ZDRAVSTVUJTE $\rightarrow$ RUSSIAN
- 規則：如果單字不在上述清單中，則輸出 UNKNOWN。讀到 # 時結束程式

#### 關鍵邏輯：
1. Mapping：使用 std::map<string, string> mp
    - Key (鍵)：儲存各國語言的「你好」
    - Value (值)：儲存對應的語言名稱
    - 優點：比起寫大量的 if-else 或 switch，使用 map 查表更為簡潔且易於維護
2. Count：
    - 使用 mp.count(s)：這會檢查 map 中是否存在該鍵
    - 如果回傳 1，表示該單字已知，輸出對應的 mp[s]
    - 如果回傳 0，表示未知，輸出 UNKNOWN
3. 格式化輸出：使用一個 count 變數來記錄當前處理到第幾個 Case

#### 模擬運算(HOLA 為例)：
- 輸入：HOLA
- 步驟 1：檢查 mp.count("HOLA")，結果為 1
- 步驟 2：存取 mp["HOLA"]，得到 "SPANISH"
- 步驟 3：輸出 Case 1: SPANISH
- Time Complexity：$O(L \log N)$。$L$ 是單字長度，$N$ 是 map 中儲存的語言數量（此題 $N=6$，幾乎可以視為常數時間）
- Space Complexity：$O(1)$。只儲存了 6 組固定的字串對照

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - Map 的應用場景：當有一對一的明確對應關係時，查表法（Lookup Table）是最優雅的解決方案
    - 終止條件判斷：使用 if (s == "#") break 處理變動數量的測試資料
    - 程式碼簡潔性：比起多重 if 分支，利用資料結構（Data Structure）驅動邏輯（Logic）能讓程式碼更清晰

#### 總結 (Takeaway)
- 語言偵測/翻譯類問題 SOP：
    1. 建立 map 並初始化所有的對應資料
    2. 讀取輸入單字並檢查是否存在於 map 的 Key 中
    3. 若存在，取出 Value；若不存在，處理預設情況
