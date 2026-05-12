#include <iostream>
using namespace std;

long long t, d, n;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> d >> n;
        n--;
        d--;
        ans = 1;
        for (int i = 0; i < d; i++){
            ans <<= 1;
            if (n & (1LL << i)) ans |= 1;
        }
        cout << ans << "\n";
    }
}
