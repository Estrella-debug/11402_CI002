#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        // 如果只有 1 阶或 2 阶，直接返回 n
        if (n <= 2) {
            return n;
        }
        
        // 使用两个变量滚动记录前两阶的方法数，空间复杂度优化至 O(1)
        int first = 1;  // 代表 n - 2 阶
        int second = 2; // 代表 n - 1 阶
        int current = 0;
        
        // 从第 3 阶开始状态转移
        for (int i = 3; i <= n; ++i) {
            current = first + second; // 当前阶数的方法数 = 前两阶方法数之和
            first = second;           // 滚动更新变量
            second = current;
        }
        
        return current;
    }
};
