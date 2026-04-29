#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // 記錄最低價格
        int maxProfit = 0;      // 記錄最大利潤
        
        for (int price : prices) {
            // 更新最低價格
            if (price < minPrice) {
                minPrice = price;
            }
            // 計算當前價格賣出的利潤，並更新最大利潤
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        
        return maxProfit;
    }
};

int main() {
    Solution solution;

    // 測試案例 1
    // 輸入: [7, 1, 5, 3, 6, 4]
    // 解釋: 在第 2 天（價格 = 1）買入，在第 5 天（價格 = 6）賣出，最大利潤 = 6-1 = 5。
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int result1 = solution.maxProfit(prices1);
    cout << "測試案例 1 的最大利潤: " << result1 << endl;

    // 測試案例 2
    // 輸入: [7, 6, 4, 3, 1]
    // 解釋: 價格一路下跌，沒有交易可以產生利潤，最大利潤 = 0。
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int result2 = solution.maxProfit(prices2);
    cout << "測試案例 2 的最大利潤: " << result2 << endl;

    return 0;
}