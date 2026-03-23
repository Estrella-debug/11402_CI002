#include <iostream>
#include <string>
#include <cctype> // 包含 isalnum 和 tolower

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // 左指標右移，直到找到字母或數字
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            // 右指標左移，直到找到字母或數字
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }
            // 比較字母（轉小寫）
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1
    std::string test1 = "A man, a plan, a canal: Panama";
    std::cout << "Test 1: " << (sol.isPalindrome(test1) ? "True" : "False") << std::endl;

    // 測試範例 2
    std::string test2 = "race a car";
    std::cout << "Test 2: " << (sol.isPalindrome(test2) ? "True" : "False") << std::endl;

    // 測試範例 3 (空字串或只有符號)
    std::string test3 = " ";
    std::cout << "Test 3: " << (sol.isPalindrome(test3) ? "True" : "False") << std::endl;

    return 0;
}