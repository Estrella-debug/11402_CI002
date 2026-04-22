### 題目：[UVa 10226 - Hardwood Species](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1167)

#### 解題思路
給定一森林中各種樹木的名稱清單，計算每一種樹木佔總數的百分比
- 輸出要求：
    - 樹木名稱須按 字典順序 (Alphabetical order) 排列
    - 百分比須精確到小數點後 四位
- 核心策略：利用 map 自動排序的特性來儲存樹名，並在讀取過程中同步累加總樹木量

#### 關鍵邏輯：
1. Frequency Mapping：
    - 使用 map<string, int> mp
    - mp[s]++：如果樹名 s 已存在，次數加 1；若不存在，map 會自動建立該鍵值並初始化。由於 map 底層是平衡樹（紅黑樹），輸出時會自然按照字母順序排列
2. Precision Calculation：
    - 總數 sum 記錄所有輸入的行數
    - 計算公式：(double)i.second / sum * 100
    - 使用 fixed 與 setprecision(4) 確保輸出符合題目的格式要求
3. Buffer Handling：
    - 這題的輸入格式較為複雜（包含測試組數、空行、含空格的樹名）
    - getline(cin, s) 被多次用來清除讀取 n 之後殘留的換行符以及測資間的空行
4. Separation：
    - 每組測試資料結束後，需輸出一個額外的空行 cout << "\n"

#### 模擬運算(一組輸入為例)：
- Step 1 (統計)：mp["Ash"] = 1, mp["Red Pine"] = 2, sum = 3
- Step 2 (排序輸出)：
    - Ash: $(1 / 3) \times 100 = 33.3333\%$
    - Red Pine: $(2 / 3) \times 100 = 66.6667\%$
- Time Complexity：$O(N \log M)$。$N$ 為總樹木數量，$M$ 為不同樹種的數量（map 的插入與尋找皆為對數時間）
- Space Complexity：$O(M \cdot L)$。$M$ 為樹種數量，$L$ 為樹名平均長度

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - IO 優化：ios_base::sync_with_stdio(0); cin.tie(0); 在處理數以萬計的字串輸入時，能顯著降低運行時間
    - getline 的必要性：因為樹名可能包含空格（例如 "White Oak"），傳統的 cin >> s 會在空格處斷開，因此必須使用 getline
    - 格式化浮點數：掌握了 fixed 與 setprecision 的搭配，這是 C++ 處理精確小數位數的標準作法
#### 總結 (Takeaway)
- 頻率統計與排序問題 SOP：
    1. 選用 map 處理需要排序的計數需求
    2. 使用 getline 處理含空格的字串輸入
    3. 注意數據類型轉換（int 轉 double），避免整數除法導致精度丟失
 