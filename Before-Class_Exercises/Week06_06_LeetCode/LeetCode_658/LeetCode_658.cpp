#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        auto it = std::lower_bound(arr.begin(), arr.end(), x);
        
        // right 指向最接近 x 且大於等於 x 的位置
        int right = std::distance(arr.begin(), it);
        // left 指向 right 的左邊，即最後一個小於 x 的位置
        int left = right - 1;

        while (k > 0) {
            if (left < 0) {
                // 如果左邊已經超出陣列邊界，只能往右邊擴展
                right++;
            } else if (right >= arr.size()) {
                // 如果右邊已經超出陣列邊界，只能往左邊擴展
                left--;
            } else if (std::abs(arr[left] - x) <= std::abs(arr[right] - x)) {
                // 如果左邊元素離 x 比較近（或距離相等時優先選左邊小的數），往左擴展
                left--;
            } else {
                // 如果右邊元素離 x 比較近，往右擴展
                right++;
            }
            // 找到了一個元素，剩餘需求數量減 1
            k--;
        }

        return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};