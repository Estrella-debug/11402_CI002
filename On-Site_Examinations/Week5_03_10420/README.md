### 題目：[UVa 10420 - List of Conquests](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361)

#### 解題思路
這題的目標是統計名單中每個國家（Country）出現的次數
- 輸入格式：每一行會先給一個國家名稱，後面跟著一個人的名字
- 輸出要求：按照國家的 字典順序 (Alphabetical order) 排列，並印出國家名及其出現總數
- 核心重點：我們只需要擷取每一行的「第一個單字」，後面的姓名資訊不影響統計

#### 關鍵邏輯：
1. 自動排序與統計 (The Power of Map)：使用 map<string, int> mp
    - 鍵 (Key)：儲存國家名稱
    - 值 (Value)：儲存該國家出現的次數
    - 優點：map 底層是紅黑樹，會自動根據 Key 進行排序，完美符合題目要求的字典序輸出
2. 字串拆解 (String Parsing)：
    - 先用 getline 讀取整行字串
    - 利用 stringstream 將該行字串轉為流（stream），再透過 >> 運算子提取第一個單詞
3. 計數累加：執行 mp[s]++。如果國家已存在，次數加 1；若不存在，map 會自動建立該 Key 並初始化次數
#### 模擬運算(以輸入為例)：
- 輸入指令數：n = 3
- 第一行：Spain Donna Elvira $\rightarrow$ 提取 Spain。mp["Spain"] = 1
- 第二行：England Jane Doe $\rightarrow$ 提取 England。mp["England"] = 1
- 第三行：Spain Anna $\rightarrow$ 提取 Spain。mp["Spain"] = 2
- Time Complexity：$O(n \log m)$。其中 $n$ 是總行數，$m$ 是不同國家的數量
- Space Complexity：$O(m)$。需要空間儲存所有不重複的國家名稱及其計數

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 緩衝區清理 (Buffer Clear)：在讀取整數 n 之後，必須先用一個額外的 getline 消耗掉換行符號 \n，否則後續第一次讀取會讀到空行
    - Stringstream 的彈性：這是在不知道後方名字有幾個單字的情況下，擷取「第一個單字」最穩定的方法
    - 範圍迴圈 (Range-based for loop)：使用 for (auto i : mp) 可以非常直覺地遍歷所有統計結果

#### 總結 (Takeaway)
- 分類統計問題 SOP：
    1. 選擇適合的容器（需要排序用 map，不需要排序可用 unordered_map）
    2. 擷取關鍵關鍵字（Key）
    3. 利用 mp[key]++ 進行計數
- 這種「對應關係」的資料處理方式，是解決大多數頻率分析或名單統計問題的核心工具