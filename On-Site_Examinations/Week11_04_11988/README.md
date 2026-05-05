### 題目：[UVa 11988 - Broken Keyboard (Beiju Text)](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3139)

#### 解題思路
你在打字時，鍵盤的 Home 鍵和 End 鍵會自動隨機按下
- '[' (Home)：代表游標跳到整行文字的最前端
- ']' (End)：代表游標跳到整行文字的最後端
- 目標：根據給定的輸入字串（包含隱藏的 Home/End 指令），輸出螢幕上最終顯示的文字順序
- 核心挑戰：如果使用 std::string 或陣列進行頻繁的「頭部插入」，每次插入都需要搬移所有字元，時間複雜度會達到 $O(N^2)$ 並導致 TLE
- 關鍵策略：使用 std::list，它支援在 $O(1)$ 時間內於指定迭代器（游標）位置插入字元

#### 關鍵邏輯：
1. 雙向鏈結串列：
    - std::list<char> line 用來儲存最終生成的文字
    - 鏈結串列的特性是插入操作不需要搬動記憶體，非常適合處理頻繁變更位置的寫入
2. 迭代器游標控制:
    - 宣告一個迭代器 it 來代表螢幕上的游標位置
    - 遇到 '['：將 it 重置到 line.begin()
    - 遇到 ']'：將 it 重置到 line.end()
    - 一般字元：使用 line.emplace(it, i)。這會在 it 指向的位置 之前 插入字元
3. 效能優化：
    - 使用 cin.tie(nullptr) 減少輸入輸出開銷
    - 使用 getline(cin, input) 讀取整行測資

#### 模擬運算(This[is]Example為例)：
- 輸入 This：游標在末尾，line = [T, h, i, s]
- 遇到 [：游標移到開頭
- 輸入 is：在開頭插入，line = [i, s, T, h, i, s]
- 遇到 ]：游標移到末尾
- 輸入 Example：在末尾插入
- 最終結果：isThisExample
- Time Complexity：$O(N)$。每個字元只會被掃描一次，且 list 插入是 $O(1)$
- Space Complexity：$O(N)$。需要空間儲存所有字元與鏈結節點

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 容器選擇的重要性：深刻體會到當題目涉及頻繁的「頭部插入」或「中間插入」時，list 遠優於 vector 或 string
    - 迭代器的運作：理解了 emplace(it, val) 會在迭代器位置前插入，且插入後迭代器會自動指向新插入元素的下一個（即保持原位）
    - IO 優化：在處理長度達 $10^5$ 的字串時，IO 的速度對總執行時間影響極大
#### 總結 (Takeaway)
- 游標型字串處理問題 SOP：
    1. 選擇支援 $O(1)$ 任意位置插入的資料結構（std::list）
    2. 利用迭代器或指針模擬游標位置
    3. 根據特殊符號更新游標至 begin() 或 end()
    4. 最終循序輸出鏈結串列內容
 