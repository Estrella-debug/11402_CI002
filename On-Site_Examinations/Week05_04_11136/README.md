### 題目：[UVa 11136 - Hoax or what](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2077)

#### 解題思路
這題描述一個抽獎活動：每天會有若干人投入小票（每一張都有金額），每天結束時會從所有小票中選出 面額最大 與 面額最小 的兩張，計算其差值並累加為當天的成本，最後將這兩張票作廢
- 核心挑戰：每天都會有新的小票加入，且必須快速找到並移除目前所有票中的最大值與最小值

#### 關鍵邏輯：
1. 自動排序與重複值 (The Power of Multiset)：使用 multiset<int> bills
    - 為什麼用 multiset？ 因為 set 會過濾掉相同金額的小票，但這題可能會有好幾張面額一樣的票。multiset 既能自動排序，又能保留重複值序，完美符合題目要求的字典序輸出
2. 極值提取 (Extracting Extremes)：
    - 最小值：即 multiset 的開頭 bills.begin()
    - 最大值：即 multiset 的末尾。因為 end() 是指向最後一個元素的下一個位置，所以要用 prev(bills.end()) 取得真正的最大值
3. 累加與移除：
    - 計算 *max_it - *min_it 並加入 total_cost
    - 使用 erase(iterator) 精確刪除 該張小票。注意：若直接傳入數值（如 erase(*min_it)），會刪掉所有面額相同的票，這是不對的
#### 模擬運算(一天為例)：
- 目前小票箱：{1, 2, 5, 10, 10}
- 步驟 1：找到最小值 1 與最大值 10
- 步驟 2：成本累加 $10 - 1 = 9$
- 步驟 3：移除一張 1 和一張 10
- 剩餘小票箱：{2, 5, 10}
- Time Complexity：$O(N \cdot K \log M)$。$N$ 天，$K$ 張新票，每次插入與刪除在紅黑樹中都是 $\log M$ 時間
- Space Complexity：$O(M)$。需要儲存當前尚未被抽出的所有小票

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 資料型態範圍：總成本 total_cost 可能會非常大，超過 int 的範圍（$2 \times 10^9$），因此必須使用 long long
    - 迭代器操作：prev() 函數在處理指向容器末尾的迭代器時非常方便
    - Erase 的陷阱：記得要用 bills.erase(iterator) 而不是 bills.erase(value)，否則會一次刪除所有相同面額的票

#### 總結 (Takeaway)
- 動態極值維護問題 SOP：
    1. 如果需要隨時加入元素並取出最大/最小，優先考慮 multiset 或兩個 priority_queue
    2. 利用迭代器存取 begin() 與最後一個元素
    3. 注意數值累加是否會溢位（Overflow）
- multiset 是一個功能強大的工具，能讓我們在 $O(\log N)$ 的時間內完成排序與查找，是處理這類「動態清單」問題的首選