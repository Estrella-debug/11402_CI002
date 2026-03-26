### 題目：[UVa 10038 - Jolly Jumpers](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=979)

#### 解題思路
這題要判斷一個含有 $n$ 個數字的數列是否為「Jolly Jumper」
- 定義：如果數列中「相鄰兩數之差的絕對值」剛好包含了從 1 到 $n-1$ 的所有整數，它就是 Jolly
- 範例：數列 4 1 4 2 3 ($n=4$)
    - 相鄰差值：$|1-4|=3, |4-1|=3, |2-4|=2, |3-2|=1$
    - 差值集合包含了 $\{1, 2, 3\}$，剛好是 $1$ 到 $n-1$，所以它是 Jolly

#### 關鍵邏輯：
1. 紀錄差值 (Track Differences)：建立一個大小為 $n$ 的布林型態 vector<bool> appeared，用來標記 $1$ 到 $n-1$ 這些差值是否出現過
2. 逐對計算：
    - 使用 abs(now - pre) 計算相鄰數字的絕對差
    - 安全檢查：必須確認差值 diff 落在 $1$ 到 $n-1$ 之間，才將 appeared[diff] 設為 true。這可以防止陣列越界（Out of bounds）
3. 完整性檢查：最後跑一遍迴圈，檢查 appeared[1] 到 appeared[n-1] 是否全部都是 true
#### 模擬運算(4 1 4 2 3 為例)：
- $n=4$，目標差值應包含 $\{1, 2, 3\}$
- 第一對 (4, 1)：$|1-4| = 3$。標記 appeared[3] = true
- 第二對 (1, 4)：$|4-1| = 3$。標記 appeared[3] = true（已存在）
- 第三對 (4, 2)：$|2-4| = 2$。標記 appeared[2] = true
- 第四對 (2, 3)：$|3-2| = 1$。標記 appeared[1] = true
- 判定：$1, 2, 3$ 都出現了，輸出 Jolly
- Time Complexity：$O(n)$。我們只需要讀取數列一次，再檢查一次標記陣列
- Space Complexity：$O(n)$。需要額外空間儲存 appeared 標記

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - 邊界處理：當 $n=1$ 時，數列只有一個數字，沒有「相鄰差值」。根據定義這也算 Jolly，需要特別寫一個 if (n == 1) 來處理
    - 動態陣列安全：使用 vector<bool> 加上範圍檢查 if (diff >= 1 && diff < n)，可以避免讀到非法數據（例如差值超大）時程式當掉
    - 連續讀取：題目沒說有幾組資料，所以用 while (cin >> n) 持續讀取直到檔案結束

#### 總結 (Takeaway)
- 數列屬性判定 SOP：
    1. 確定目標集合（如 $1$ 到 $n-1$）
    2. 利用布林陣列作為「記錄本」
    3. 遍歷資料並在記錄本上打勾
    4. 最後檢查記錄本是否有漏掉任何勾勾
- 這種「打勾標記法」是處理集合完整性問題最快且最穩定的方式