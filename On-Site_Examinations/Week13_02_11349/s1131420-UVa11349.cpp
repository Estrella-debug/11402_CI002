#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
        string a, b; // 讀掉 N = 的部分
        int N;
        cin >> a >> b >> N;
        
        vector <vector<ll>> M(N, vector<ll>(N));
        
        bool isSymmetric = true;
        
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                cin >> M[i][j];
                if (M[i][j] < 0) isSymmetric = false; 
            }
        }
        
        if (isSymmetric){
            for (int i = 0; i < N && isSymmetric; ++i){
                for (int j = 0; j < N && isSymmetric; ++j){
                    if (M[i][j] != M[N - 1 - i][N - 1 - j]){
                        isSymmetric = false;
                    }
                }
            }
        }
        
        cout << "Test #" << t << ": " << (isSymmetric ? "Symmetric." : "Non-symmetric.") << '\n';
    }
    return 0;
}
