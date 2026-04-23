#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If it's a closing bracket, the stack must not be empty
                // and the top of the stack must match the closing bracket
                if (st.empty()) return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                st.pop(); // Matching pair found, remove from stack
            }
        }
        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};

int main() {
    Solution sol;

    // 測試範例 1: 正確的成對括號
    std::string s1 = "()[]{}";
    std::cout << "Test 1: \"" << s1 << "\" -> " << (sol.isValid(s1) ? "True" : "False") << std::endl;

    // 測試範例 2: 正確的嵌套括號
    std::string s2 = "([{}])";
    std::cout << "Test 2: \"" << s2 << "\" -> " << (sol.isValid(s2) ? "True" : "False") << std::endl;

    // 測試範例 3: 錯誤的順序
    std::string s3 = "(]";
    std::cout << "Test 3: \"" << s3 << "\" -> " << (sol.isValid(s3) ? "True" : "False") << std::endl;

    // 測試範例 4: 括號類型不匹配
    std::string s4 = "([)]";
    std::cout << "Test 4: \"" << s4 << "\" -> " << (sol.isValid(s4) ? "True" : "False") << std::endl;

    // 測試範例 5: 只有左括號 (堆疊最終不為空)
    std::string s5 = "[(";
    std::cout << "Test 5: \"" << s5 << "\" -> " << (sol.isValid(s5) ? "True" : "False") << std::endl;

    return 0;
}