#include <iostream>
using namespace std;
  
int solve(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    if (ret < 10) return ret;
    else return solve(ret);
}
  
int main() {
    int n;
    while (cin >> n && n) {
        cout << solve(n) << "\n";
    }
    return 0;
}