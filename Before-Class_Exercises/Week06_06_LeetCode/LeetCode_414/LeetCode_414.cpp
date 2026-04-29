#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 使用指標來代表是否已經找到前三大數，初始化為 nullptr 代表尚未找到
        long* max1 = nullptr; // 第一大
        long* max2 = nullptr; // 第二大
        long* max3 = nullptr; // 第三大
        
        for (int& num : nums) {
            // 檢查當前數字是否已經在我們記錄的前三大中
            // 如果重複出現，則跳過，確保我們找的是「相異」的前三大數
            if ((max1 && num == *max1) || (max2 && num == *max2) || (max3 && num == *max3)) {
                continue;
            }
            
            // 更新邏輯：從第一大開始逐一比較
            if (max1 == nullptr || num > *max1) {
                // 如果比第一大還大，原有的第一大退到第二，第二退到第三
                max3 = max2;
                max2 = max1;
                max1 = new long(num);
            } else if (max2 == nullptr || num > *max2) {
                // 如果比第二大還大，原有的第二大退到第三
                max3 = max2;
                max2 = new long(num);
            } else if (max3 == nullptr || num > *max3) {
                // 如果只比第三大還大，直接更新第三大
                max3 = new long(num);
            }
        }
        
        // 返回結果：
        // 依照題目要求，如果「第三大」不存在（即 max3 仍為 nullptr），
        // 則回傳「第一大」的值。
        if (max3 == nullptr) {
            return (int)*max1;
        }
        return (int)*max3;
    }
};