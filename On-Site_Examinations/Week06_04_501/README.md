### 題目：[UVa 501 - Black Box](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=442)

#### 解題思路
有一個名為「Black Box」的資料結構，包含兩種操作：
1. ADD(x)：將一個元素放入箱中
2. GET：回傳箱中第 $i$ 小的元素。每次呼叫 GET 之後，$i$ 會自動加 1（初始 $i=1$）
- 關鍵挑戰：資料是不斷動態增加的，且我們需要維護一個會移動的「第 $i$ 小」指標

#### 關鍵邏輯：
1. 有序容器 (Ordered Container)：使用 multiset<int> ms 來儲存數字。它能自動排序並容納重複值
2. 迭代器追蹤 (Iterator Tracking)：這是本題最巧妙的地方。我們不使用索引，而是維護一個指向目前「第 $i$ 小元素」的 迭代器 (Iterator) it
3. 插入後的調整 (Update after ADD)：
    - 當新元素 add[i] 小於目前 it 指向的值時，由於新成員擠進了左半邊，原本的第 $i$ 小元素實際上會往右偏移一個位置。為了維持 it 依然指向「目前的第 $i$ 小」，我們必須將 it 向左移一位 (--it)
4. 獲取後的調整 (Update after GET)：
    - 每次執行 GET 操作，意味著下一次要找的是第 $i+1$ 小的數
    - 因此，在輸出 *it 之後，將 it 向右移一位 (++it)，為下一次 GET 做準備
#### 模擬運算(ADD(3), ADD(1), GET, GET 為例)：
- ADD(3)：ms = {3}, it 初始化指向 3 (第 1 小)
- ADD(1)：ms = {1, 3}。因為 1 < *it (即 1 < 3)，執行 --it。現在 it 指向 1
- GET：輸出 *it (即 1)。隨後執行 ++it，it 指向 3
- GET：輸出 *it (即 3)。隨後執行 ++it，it 移至 ms.end()
- Time Complexity：$O((M+N) \log M)$。每次插入與迭代器移動均為對數級或常數級時間
- Space Complexity：$O(M)$。需要空間儲存所有加入箱中的數字

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 迭代器的持久性：在 multiset 中，插入新元素不會導致原有的迭代器失效（除非該節點被刪除），這使得我們可以長期持有一個「基準點」
    - 指標移動邏輯：理解「新元素在左邊還是右邊」對順位指標的影響，是解決動態順序問題的精髓
    - 空行輸出：UVa 題目對格式極其嚴格，多組測試資料間的 if (t > 0) cout << endl; 是避免 Presentation Error 的關鍵

#### 總結 (Takeaway)
- 動態 $k$ 小值問題 SOP：
    1. 選擇一個支援自動排序且迭代器穩定的容器
    2. 定義一個指標（或迭代器）守住目前的第 $k$ 名
    3. 根據新加入元素與目前指標的「大小關係」，決定指標要左移、右移還是不動
- 這種「滑動指標」的概念比每次重新排序或使用 $O(k)$ 的 std::nth_element 效率高得多