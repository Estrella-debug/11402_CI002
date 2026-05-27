#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, r;
    cin >> T;
    while (T--) {
        cin >> r;
        vector<int> s(r);
        for (int i = 0; i < r; i++){
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        int sum = 0;
        for (int i = 0; i < r; i++){
            sum += abs(s[i] - s[r/2]);
        }
        cout << sum << "\n";
    }
    return 0;
}