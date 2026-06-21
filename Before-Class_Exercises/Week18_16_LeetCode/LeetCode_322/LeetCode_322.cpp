#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 创建 DP 数组，初始化为一个不可能的最大值 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        
        // 基础状态：凑齐金额 0 需要 0 个硬币
        dp[0] = 0;
        
        // 外层循环遍历所有可能的目标金额
        for (int i = 1; i <= amount; ++i) {
            // 内层循环遍历每一种硬币面额
            for (int coin : coins) {
                // 如果当前硬币面额小于或等于目标金额，说明该硬币可用
                if (i - coin >= 0) {
                    // 状态转移方程：取当前硬币和不取当前硬币的最小值
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // 如果 dp[amount] 仍然是初始的最大值，说明无法凑出该金额，返回 -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
