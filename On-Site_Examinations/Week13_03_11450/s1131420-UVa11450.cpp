#include <iostream>
#include <cstring>
using namespace std;
int T, M, C;
int dp[205][25];
int price[25][25];
 
int shop(int money, int g){
    if (money < 0) return -1e9;
    if (g == C) return M - money;
    int &ans = dp[money][g];
    if (ans != -1) return ans;
    for (int i = 1; i <= price[g][0]; i++){
        ans = max(ans, shop(money - price[g][i], g+1));
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--){
        cin >> M >> C;
        for (int i = 0; i < C; i++){
            cin >> price[i][0]; // K
            for (int j = 1; j <= price[i][0]; j++){
                cin >> price[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans = shop(M, 0);
        if (ans < 0) cout << "no solution\n";
        else cout << ans << "\n";
    }
    return 0;
}