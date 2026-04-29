#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Count frequency of each number in arr1
        // 題目通常限制數值範圍在 0-1000 之間
        int count[1001] = {0};
        for (int num : arr1) count[num]++;
        
        vector<int> res;
        // Step 2: Add elements to res in the order specified by arr2
        for (int num : arr2) {
            while (count[num] > 0) {
                res.push_back(num);
                count[num]--;
            }
        }
        
        // Step 3: Add remaining elements (not in arr2) in ascending order
        for (int i = 0; i <= 1000; ++i) {
            while (count[i] > 0) {
                res.push_back(i);
                count[i]--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    vector<int> arr1_1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2_1 = {2, 1, 4, 3, 9, 6};
    
    vector<int> result1 = sol.relativeSortArray(arr1_1, arr2_1);

    cout << "Example 1 Result: ";
    for (int num : result1) {
        cout << num << " ";
    }
    // 預期輸出: 2 2 2 1 4 3 3 9 6 7 19
    cout << endl;

    // 測試範例 2
    vector<int> arr1_2 = {28, 6, 22, 8, 44, 17};
    vector<int> arr2_2 = {22, 28, 8, 6};
    
    vector<int> result2 = sol.relativeSortArray(arr1_2, arr2_2);

    cout << "Example 2 Result: ";
    for (int num : result2) {
        cout << num << " ";
    }
    // 預期輸出: 22 28 8 6 17 44
    cout << endl;

    return 0;
}