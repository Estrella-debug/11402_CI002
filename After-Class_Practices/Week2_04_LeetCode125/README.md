### 題目：[125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

#### 解題思路
這題的目標是判斷一個字串是不是「迴文（Palindrome）」
- 規則：
    1. 只看字母和數字
    2. 忽略大小寫
    3. 符號、標點和空格通通跳過
- 範例："A man, a plan, a canal: Panama" 整理後是 amanaplanacanalpanama，正著讀反著讀都一樣，所以是 True

#### 關鍵邏輯：
1. 雙指標法 (Two Pointers)：
    - left：從字串開頭往右走
    - right：從字串末尾往左走
2. 過濾雜訊：利用 std::isalnum() 函數。只要不是字母或數字，指標就直接跳過（Increment/Decrement），不需要處理
3. 格式統一：在比較之前，利用 std::tolower() 將字元轉成小寫，這樣就不會因為大小寫不同而誤判
4. 碰撞停止：只要 left < right，迴圈就持續進行。如果中途發現對應位置的字元不一樣，立即判定為 false

#### 模擬運算("race a car" 為例)：
- 第一步：left 指向 'r', right 指向 'r'。兩者相同，繼續
- 第二步：left 指向 'a', right 指向 'a'。兩者相同，繼續
- 第三步：left 指向 'c', right 指向空格 $\rightarrow$ right 跳過空格指向 'c'。兩者相同，繼續
- 第四步：left 指向 'e', right 指向 'a'。不相同！
- 結果：回傳 false
- Time Complexity：$O(n)$。雖然有巢狀 while，但每個字元最多只會被 left 或 right 掃描到一次
- Space Complexity：$O(1)$。我們是在原地進行比較，沒有開新的字串

#### 語言差異與踩坑紀錄
* **學到了什麼：**
    - cctype 函式庫：isalnum (Is Alphanumeric) 和 tolower (To Lower) 是處理字串題目的「神器」，可以省下寫 if (s[i] >= 'a' && ...) 的時間
    - 邊界判斷：在內部 while 跳過字元時，一定要再次檢查 left < right，否則當字串全是符號時，指標可能會跑過頭。
    - 原地處理 vs 新開字串：雖然可以先用一個新字串存好過濾後的內容再去反轉，但「雙指標法」更省記憶體（只需要兩個整數空間）

#### 總結 (Takeaway)
- 迴文判定問題 SOP：
    1. 建立左右兩個指標
    2. 用 while 搭配條件跳過無效字元
    3. 統一大小寫後進行比對
    4. 指標往中間靠攏直到相遇
- 這種「在雜訊中尋找規律」的雙指標技巧，是處理字串搜尋非常重要的基礎