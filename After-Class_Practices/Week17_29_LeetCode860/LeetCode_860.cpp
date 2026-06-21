#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int five = 0; // 记录手上 5 美元的数量
        int ten = 0;  // 记录手上 10 美元的数量

        for (int bill : bills) {
            if (bill == 5) {
                // 顾客给 5 美元，直接收下，无需找零
                five++;
            } 
            else if (bill == 10) {
                // 顾客给 10 美元，必须找零 5 美元
                if (five == 0) return false;
                five--;
                ten++;
            } 
            else { // bill == 20
                // 顾客给 20 美元，需要找零 15 美元
                // 优先贪心策略：先用 10 + 5 找零（因为 5 美元比 10 美元更万能）
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                // 如果没有 10 美元，只能用 3 张 5 美元找零
                else if (five >= 3) {
                    five -= 3;
                } 
                // 无法找零，返回 false
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
