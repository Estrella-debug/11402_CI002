#include <bits/stdc++.h>
using namespace std;

int Case, n, m, a, id[1000005];
queue <int> team[1005], q;

int main() {
    while (cin >> n){
        if (n == 0) break;
        Case++;
        cout << "Scenario #" << Case << "\n";
        for (int i = 1; i <= n; i++){
            cin >> m;
            for (int j = 0; j < m; j++){
                cin >> a;
                id[a] = i;
            }
        }
        string s;
        while (cin >> s){
            if (s == "STOP") break;
            if (s == "ENQUEUE"){
                cin >> a;
                if (team[id[a]].empty()) q.push(id[a]);
                team[id[a]].push(a);
            }
            else if (s == "DEQUEUE"){
                int now = q.front();
                cout << team[now].front() << "\n";
                team[now].pop();
                if (team[now].empty()) q.pop();
            }
        }
        cout << "\n";
        while (!q.empty()){
            int now = q.front();
            while (!team[now].empty()) team[now].pop();
            q.pop();
        }
    }
}
