### 題目：[UVa 299 - Train Swapping](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=235)

#### 解題思路
想像一個火車軌道，車廂（carriage）的編號亂掉了。我們唯一的工具是一個「調度裝置」，它每次只能交換 相鄰（Adjacent） 的兩個車廂
- 目標：計算將所有車廂按順序（1, 2, 3...）排好，最少需要交換幾次
- 核心概念：在電腦科學中，這種「只交換相鄰元素」來達成排序的方法，就是最標準的 氣泡排序 (Bubble Sort)

#### 關鍵邏輯：
1. 物理限制：因為只能交換相鄰位置，這代表我們每做一次交換，就是在消除一個「逆序對（Inversion）」
2. 氣泡排序 (Bubble Sort)：
    - 兩兩比較：從頭開始，比較 a[j] 和 a[j+1]
    - 執行交換：如果左邊比右邊大（a[j] > a[j+1]），就交換它們，並讓計數器 cnt 加 1
    - 重複執行：大數字會像氣泡一樣慢慢「浮」到最右邊
3. 精準輸出：題目對輸出格式要求嚴格，必須完整印出 Optimal train swapping takes X swaps.

#### 模擬運算(3, 2, 1 為例)：
- 第一輪 (i=0)：
    - 比較 3 和 2 $\rightarrow$ 交換 [2, 3, 1]，cnt = 1
    - 比較 3 和 1 $\rightarrow$ 交換 [2, 1, 3]，cnt = 2。 (3 已到位)
- 第二輪 (i=1)：
    - 比較 2 和 1 $\rightarrow$ 交換 [1, 2, 3]，cnt = 3。 (2 已到位)
- 結果：共交換 3 次
- Time Complexity：$O(N^2)$。因為有兩層 for 迴圈
- Space Complexity：$O(N)$。使用 vector 儲存車廂編號

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - Vector 的好處：使用 std::vector<int> a(N) 比傳統陣列 int a[N] 更安全，它能動態分配記憶體，避免在某些編譯器上出現問題
    - 交換次數的意義：這題其實是在考「逆序數（Inversion Number）」。雖然可以用更快的演算法（如合併排序）來算，但題目規模 $N \le 50$ 很小，使用氣泡排序最直覺且符合題目描述
    - 嚴謹讀取：使用 while(T--) 處理多組測資，並搭配 if (!(cin >> N)) break; 確保資料讀取安全

#### 總結 (Takeaway)
- 相鄰交換問題 SOP：
    1. 確認題目是否限定「只能交換相鄰元素」
    2. 若是，直接聯想Bubble Sort
    3. 在交換邏輯中加入計數器
- 氣泡排序雖然在處理大數據時較慢，但在理解「排序成本」與「元素移動」的邏輯上非常重要