#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int t, Case, n, d, m, mx, prea, preb;
char c, c2;
vector <int> b, s;
 
int main(){
    cin >> t;
    while (t--){
        cin >> n >> d;
        b.clear();
        s.clear();
        for (int i = 0; i < n; i++){
            cin >> c >> c2 >> m;
            if (c == 'B') b.push_back(m);
            else s.push_back(m);
        }
        mx = 0;
        prea = 0;
        preb = 0;
        reverse(b.begin(), b.end());
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++){
            if (s.empty() || (!b.empty() && b.back() < s.back())){
                mx = max(mx, b.back()-prea);
                prea = b.back();
                mx = max(mx, b.back()-preb);
                preb = b.back();
                b.pop_back();
            }
            else{
                if (prea <= preb){
                    mx = max(mx, s.back()-prea);
                    prea = s.back();
                }
                else{
                    mx = max(mx, s.back()-preb);
                    preb = s.back();
                }
                s.pop_back();
            }
        }
        mx = max(mx, max(d-prea, d-preb));
        Case++;
        cout << "Case " << Case << ": " << mx << "\n";
    }
}