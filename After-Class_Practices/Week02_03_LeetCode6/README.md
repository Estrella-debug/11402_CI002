### 題目：[6. Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/description/)

#### 解題思路
將一個字串按照「Z 字形（Zigzag）」在給定的行數 numRows 中排列，然後由左到右、由上而下逐行讀取出來
- 重點：我們不需要真的畫出一個二維矩陣，只需要把每一行該有的字元先存在一起，最後再拼起來即可

#### 關鍵邏輯：
1. 邊界檢查 (Edge Cases)：如果 numRows 是 1，或是字串長度比行數還短，直接回傳原字串，不用進行任何處理
2. 方向控制 (Direction Flag)：
    - 我們用 curRow 記錄目前在哪一行
    - 我們用 goingDown 這個布林值來當「開關」
    - 轉折點：當我們走到第 0 行或最後一行（numRows - 1）時，就將 goingDown 反轉（!goingDown）
3. 行容器 (Row Containers)：使用 vector<string>，每一格代表一行，依序把字元 push_back 進去

#### 模擬運算(s = "PAYPAL", numRows = 3 為例)：
- P：curRow = 0，加入 rows[0]。觸發轉向：goingDown = true
- A：curRow = 1，加入 rows[1]
- Y：curRow = 2，加入 rows[2]。觸發轉向：goingDown = false
- P：curRow = 1，加入 rows[1]
- A：curRow = 0，加入 rows[0]。觸發轉向：goingDown = true
- L：curRow = 1，加入 rows[1]
- 合併結果：rows[0] + rows[1] + rows[2] = "PA" + "APL" + "Y" = "PAAPLY"
- Time Complexity：$O(n)$。$n$ 是字串長度，每個字元只會被走訪一次
- Space Complexity：$O(n)$。需要額外空間儲存這些分行後的字串

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 模擬勝於數學：這題如果想找純數學規律（例如找出每個索引的公式）會非常痛苦。直接模擬「人在走樓梯」上下移動的過程，邏輯反而更清楚
    - 方向切換技巧：利用一個 bool 變數在邊界處執行 !flag，是處理來回反覆（Oscillation）問題的標準做法
    - std::min 的運用：在初始化 vector 大小時，取 numRows 與字串長度的最小值，可以避免不必要的空間浪費

#### 總結 (Takeaway)
- Zigzag 排列問題 SOP：
    1. 建立 numRows 個字串容器
    2. 遍歷字串，將字元塞入當前行
    3. 判斷是否撞到頂部或底部，決定下一行要向上還是向下走
    4. 最後把所有行黏起來
- 這種「模擬路徑」的技巧在處理各種字串變換、圖案生成題目中非常強大