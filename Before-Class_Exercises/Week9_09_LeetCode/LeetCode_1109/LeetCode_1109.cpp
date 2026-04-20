#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 1. Initialize difference array with size n+1 to handle last+1
        vector<int> diff(n + 1, 0);

        // 2. Process each booking
        for (const auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            
            // Difference array update: +seats at start, -seats after end
            diff[first - 1] += seats;
            if (last < n) {
                diff[last] -= seats;
            }
        }

        // 3. Reconstruct the answer using prefix sum
        vector<int> ans(n);
        int current_seats = 0;
        for (int i = 0; i < n; ++i) {
            current_seats += diff[i];
            ans[i] = current_seats;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    // bookings = [[1, 2, 10], [2, 3, 20], [2, 5, 25]], n = 5
    // 說明：
    // 航班 1 到 2 訂 10 個位子
    // 航班 2 到 3 訂 20 個位子
    // 航班 2 到 5 訂 25 個位子
    vector<vector<int>> bookings1 = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n1 = 5;
    vector<int> result1 = sol.corpFlightBookings(bookings1, n1);

    cout << "Example 1 Result: ";
    for (int seats : result1) {
        cout << seats << " ";
    }
    cout << endl; // 預期輸出: 10 55 45 25 25

    // 測試範例 2
    // bookings = [[1, 2, 5], [3, 3, 5]], n = 3
    vector<vector<int>> bookings2 = {{1, 2, 5}, {3, 3, 5}};
    int n2 = 3;
    vector<int> result2 = sol.corpFlightBookings(bookings2, n2);

    cout << "Example 2 Result: ";
    for (int seats : result2) {
        cout << seats << " ";
    }
    cout << endl; // 預期輸出: 5 5 5

    return 0;
}