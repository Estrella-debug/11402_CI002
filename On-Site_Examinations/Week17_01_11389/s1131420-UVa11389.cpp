#include <iostream>
#include <algorithm>
using namespace std;
 
int n, d, r, a[105], b[105], ans;
 
int main(){
    while (cin >> n >> d >> r){
        if (n == 0) break;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(a, a+n);
        sort(b, b+n);
        reverse(b, b+n);
        ans = 0;
        for (int i = 0; i < n; i++){
            if (a[i] + b[i] > d){
                ans += r * (a[i] + b[i] - d);
            }
        }
        cout << ans << "\n";
    }
}