#include <iostream>
using namespace std;

long long n, a[105][105], ans, total;

int main() {
    while (cin >> n){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
                a[i][j] += a[i][j-1];
            }
        }
        ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j <= n; j++){
                total = 0;
                for (int k = 1; k <= n; k++){
                    total += a[k][j]-a[k][i];
                    ans = max(ans, total);
                    if (total < 0) total = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}
