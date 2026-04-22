#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int N, M;
    while (cin >> N >> M && (N != 0 && M != 0)){
        vector <int> num(N);
        for (int i = 0; i < N; ++i) cin >> num[i];
        sort(num.begin(), num.end(), [M](const int& a, const int& b){
            int ma = a % M, mb = b % M;
            if (ma != mb) return ma < mb; // 前小後大 -> 升序
            
            bool a_odd = a % 2 != 0;
            bool b_odd = b % 2 != 0;
            
            // 假設 b_odd = false;
            if (a_odd != b_odd) return a_odd; // 奇數在前
            
            if (a_odd && b_odd) return a > b; // 大奇數在前 -> 表示就要降序
            
            return a < b; // 小偶數在前 -> 表示就要升序
        });
        
        cout << N << " " << M << '\n';
        for (const int& i : num){
            cout << i << '\n';
        }
    }
    cout << "0 0\n";
}
