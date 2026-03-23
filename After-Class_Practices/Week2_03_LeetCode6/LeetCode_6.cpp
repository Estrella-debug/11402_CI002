#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // 邊界情況：只有一行或行數大於等於字串長度
        if (numRows == 1 || s.length() <= (size_t)numRows) return s;

        std::vector<std::string> rows(std::min(numRows, int(s.length())));
        int curRow = 0;
        bool goingDown = false;

        // 模擬 Z 字形排列
        for (char c : s) {
            rows[curRow] += c;
            // 到達第一行或最後一行時翻轉方向
            if (curRow == 0 || curRow == numRows - 1) 
                goingDown = !goingDown;
            
            curRow += goingDown ? 1 : -1;
        }

        // 合併所有行
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // 測試案例 1
    std::string s1 = "PAYPALISHIRING";
    int rows1 = 3;
    std::string result1 = sol.convert(s1, rows1);
    std::cout << "Input: s = \"" << s1 << "\", numRows = " << rows1 << std::endl;
    std::cout << "Output: \"" << result1 << "\"" << std::endl;
    // 預期輸出: "PAHNAPLSIIGYIR"

    std::cout << "--------------------" << std::endl;

    // 測試案例 2
    std::string s2 = "PAYPALISHIRING";
    int rows2 = 4;
    std::string result2 = sol.convert(s2, rows2);
    std::cout << "Input: s = \"" << s2 << "\", numRows = " << rows2 << std::endl;
    std::cout << "Output: \"" << result2 << "\"" << std::endl;
    // 預期輸出: "PINALSIGYAHRPI"

    return 0;
}