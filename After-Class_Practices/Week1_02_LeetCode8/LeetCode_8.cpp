#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long sum = 0;
        int i = 0;
        int sign = 1;

        while (isspace(s[i])) { i++; }

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        while (s[i] == '0') { i++; }

        int len = 0;
        while (isdigit(s[i])) {
            sum = sum * 10 + s[i] - '0';
            i++;
            len++;
            if (len > 10)
                break;
        }

        sum = sum * sign;
        if (sum > 2147483647)
            return 2147483647;
        else if (sum < -2147483648)
            return -2147483648;
        else
            return sum;
    }
};

int main() {
    Solution s;
    string s1 = "123";
    cout << s.myAtoi(s1) << "\n";
    string s2 = "0032";
    cout << s.myAtoi(s2) << "\n";
    string s3 = "4193 with words";
    cout << s.myAtoi(s3) << "\n";
    string s4 = "   -42";
    cout << s.myAtoi(s4) << "\n";
    string s5 = "-91283472332";
    cout << s.myAtoi(s5) << "\n";
    string s6 = "+1";
    cout << s.myAtoi(s6) << "\n";
    string s7 = "20000000000000000000";
    cout << s.myAtoi(s7) << "\n";
    string s8 = "  0000000000012345678";
    cout << s.myAtoi(s8) << "\n";
    string s9 = "00000-42a1234";
    cout << s.myAtoi(s9) << "\n";
    return 0;
}