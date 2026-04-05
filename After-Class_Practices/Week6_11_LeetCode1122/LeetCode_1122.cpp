#include <iostream>

#include <vector>

#include <map>

#include <algorithm>



class Solution {

public:

    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {

        // Step 1: 使用 std::map 統計 arr1 中每個數字出現的次數

        // std::map 會自動根據 Key (數值) 由小到大排序

        std::map<int, int> counts;

        for (int x : arr1) {

            counts[x]++;

        }



        std::vector<int> result;

        

        // Step 2: 依照 arr2 的順序將元素放入 result

        for (int x : arr2) {

            while (counts[x] > 0) {

                result.push_back(x);

                counts[x]--;

            }

        }



        // Step 3: 處理剩下不在 arr2 中的元素

        // 因為 std::map 遍歷時是從小到大，所以剩餘元素會自然符合升序排列

        for (auto const& [val, freq] : counts) {

            int remaining = freq;

            while (remaining > 0) {

                result.push_back(val);

                remaining--;

            }

        }

        return result;

    }

};



int main() {

    Solution sol;

    // 測試範例 1

    std::vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};

    std::vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    std::vector<int> result = sol.relativeSortArray(arr1, arr2);

    // 輸出結果

    std::cout << "Sorted Array: ";

    for (int i = 0; i < result.size(); ++i) {

        std::cout << result[i] << (i == result.size() - 1 ? "" : ", ");

    }

    std::cout << std::endl;

    // 預期輸出: 2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19

    return 0;

}