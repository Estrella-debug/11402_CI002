### 題目：[UVa 10062 - Tell me the frequencies!](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1003)

#### 解題思路
讀取一段文字，統計每個字元出現的次數
- 排序規則：
    1. 按 出現次數 由小到大排序
    2. 如果出現次數相同，則按 ASCII 碼 由大到小排序
- 輸出格式：印出字元的 ASCII 碼以及它出現的次數

#### 關鍵邏輯：
1. 資料結構 (Data Structure)：使用 pair<int, int> x[256] 來儲存資訊
    - x[i].first：存放出現次數 (Frequency)
    - x[i].second：存放該字元的 ASCII 碼
2. 統計頻率：利用字元的 ASCII 碼作為陣列索引，直接累加次數：x[(int)s[i]].first++
3. 自定義排序 (Custom Sort)：
    - 寫一個 cmp 函式：
        - 如果次數不同，回傳 x.first < y.first（次數小的在前）
        - 如果次數相同，回傳 x.second > y.second（ASCII 碼大的在前）
4. 連續讀取：使用 while(getline(cin, s)) 確保包含空白字元的整行內容都能被正確讀取
#### 模擬運算(AAABBC 為例)：
- 統計結果：
    - 'A' (ASCII 65): 3 次
    - 'B' (ASCII 66): 2 次
    - 'C' (ASCII 67): 1 次
- 排序過程：
    - 'C' 次數最少 (1)，排第一
    - 'B' 次數次之 (2)，排第二
    - 'A' 次數最多 (3)，排第三
- Time Complexity：$O(N + K \log K)$。$N$ 是字串長度，$K$ 是字元集大小
- Space Complexity：$O(K)$。需要固定大小為 256 的陣列來記錄

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - Pair 的妙用：pair<int, int> 結合 sort 可以非常方便地處理兩組數據的關聯排序
    - ASCII 轉換：字元在本質上就是整數，可以直接強制轉型 (int) 來當作陣列的 Index
    - 輸出陷阱：UVa 這類題目通常要求每組輸出之間有一個空行，但最後一組之後不需要。雖然程式碼中簡單使用 cout << endl，但在正式比賽中可能需要判斷是否為第一組來決定空行位置

#### 總結 (Takeaway)
- 字元頻率排序 SOP：
    1. 準備一個長度為 256 的計數陣列
    2. 遍歷字串進行計數
    3. 根據題目要求的「多重條件」撰寫比較函式
    4. 排序後濾除次數為 0 的項目並輸出
- 掌握自定義排序規則是解決複雜統計問題的關鍵