#include <iostream>
#include <string>
#include <stack>
#include <cctype> // for isdigit

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> counts;
        std::stack<std::string> resultStack;
        std::string currentStr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // 處理多位數數字，例如 "100["
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                // 遇到左括號，把目前的倍數和字串存入堆疊，準備處理括號內的內容
                counts.push(k);
                resultStack.push(currentStr);
                // 重置計數器與當前字串
                k = 0;
                currentStr = "";
            } else if (c == ']') {
                // 遇到右括號，開始解碼：取出倍數和之前的進度
                std::string temp = currentStr;
                currentStr = resultStack.top();
                resultStack.pop();
                
                int repeatCount = counts.top();
                counts.pop();
                
                // 將括號內的字串重複 repeatCount 次並串接到之前的進度後
                while (repeatCount-- > 0) {
                    currentStr += temp;
                }
            } else {
                // 一般字元，直接加到目前的字串中
                currentStr += c;
            }
        }
        return currentStr;
    }
};

int main() {
    Solution sol;

    // 測試範例 1: 基本重複
    std::string s1 = "3[a]2[bc]";
    std::cout << "Test 1: " << s1 << " -> " << sol.decodeString(s1) << std::endl;
    // 預期輸出: "aaabcbc"

    // 測試範例 2: 嵌套重複
    std::string s2 = "3[a2[c]]";
    std::cout << "Test 2: " << s2 << " -> " << sol.decodeString(s2) << std::endl;
    // 預期輸出: "accaccacc"

    // 測試範例 3: 多個不同倍數與組合
    std::string s3 = "2[abc]3[cd]ef";
    std::cout << "Test 3: " << s3 << " -> " << sol.decodeString(s3) << std::endl;
    // 預期輸出: "abcabccdcdcdef"

    // 測試範例 4: 處理多位數數字
    std::string s4 = "10[a]";
    std::cout << "Test 4: " << s4 << " -> " << sol.decodeString(s4) << std::endl;
    // 預期輸出: "aaaaaaaaaa"

    return 0;
}