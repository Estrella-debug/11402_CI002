#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int n, m;
    int field_num = 1;
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    while (cin >> n >> m && (n != 0 && m != 0)){
        vector <string> field(n);
        
        for (int i = 0; i < n; ++i){
            cin >> field[i];
        }
        
        vector <string> result = field;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (field[i][j] != '*'){
                    int count = 0;
                    for (int dir = 0; dir < 8; ++dir){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if (nx >= 0 && nx < n && ny >=0 && ny < m){
                            if (field[nx][ny] == '*'){
                                count++;
                            }
                        }
                    }
                    result[i][j] = count + '0';
                }
            }
        }
        
        if (field_num > 1){
            cout << "\n";
        }
        
        cout << "Field #" << field_num++ << ":\n";
        
        for (const string& s : result){
            cout << s << "\n";
        }
        
    }
    
    return 0;
}
