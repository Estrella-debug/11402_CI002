#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    vector<long long> v;
    
    // 持續讀取輸入直到檔案結尾
    while (cin >> n) {
        v.push_back(n);
        
        // 每次加入新數後排序（可用 insert 搭配 lower_bound 優化）
        sort(v.begin(), v.end());
        
        int size = v.size();
        if (size % 2 == 1) {
            // 奇數個：中間元素
            cout << v[size / 2] << endl;
        } else {
            // 偶數個：中間兩個的平均值
            cout << (v[size / 2] + v[size / 2 - 1]) / 2 << endl;
        }
    }
    
    return 0;
}
