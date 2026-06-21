#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 1. 统计每个字符最后一次出现的下标
        int lastPos[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            lastPos[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0; // 当前区间的起始位置
        int end = 0;   // 当前区间的结束位置

        // 2. 双指针贪心划分区间
        for (int i = 0; i < s.length(); ++i) {
            // 更新当前区间内字符所能到达的最远位置
            end = max(end, lastPos[s[i] - 'a']);
            
            // 如果遍历指针到达了当前区间的最大右边界
            if (i == end) {
                result.push_back(end - start + 1); // 记录区间长度
                start = i + 1;                     // 更新下一个区间的起始位置
            }
        }

        return result;
    }
};

// 示例测试
int main() {
    Solution solution;
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> res1 = solution.partitionLabels(s1);
    
    cout << "输出: ";
    for (int len : res1) cout << len << " "; // 预期输出: 9 7 8 
    cout << endl;
    return 0;
}
