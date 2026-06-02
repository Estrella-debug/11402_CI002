#include <iostream>
using namespace std;

int t, Case, n, ans, r;
string s;

int main(){
    cin >> t;
    while (t--){
        cin >> n;
        cin >> s;
        ans = 0;
        r = -1;
        for (int i = 0; i < n; i++){
            if (s[i] == '.' && i > r){
                r = i+2;
                ans++;
            }
        }
        Case++;
        cout << "Case " << Case << ": " << ans << "\n";
    }
}
