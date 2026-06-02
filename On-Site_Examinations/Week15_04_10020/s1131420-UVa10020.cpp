#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second

pii seg[100005];

int main() {
    int T, M;
    cin >> T;
    while (T--){
        cin >> M;
        int L, R, N = 0;
        while (cin >> L >> R){
            if (L == 0 && R == 0) break;
            seg[N] = {L, R};
            N++;
        }
        sort(seg, seg+N);
        L = 0;
        vector <pii> ans;
        int i = 0;
        while (L < M){
            bool find = false;
            int mxR = 0, mxI = -1;
            while (i < N){
                if (seg[i].F <= L){
                    find = true;
                    if (seg[i].S > mxR){
                        mxR = seg[i].S;
                        mxI = i;
                    }
                } else break;
                i++;
            }
            if (!find) break;
            else {
                ans.push_back(seg[mxI]);
                L = mxR;
            }
        }
        if (L >= M) {
            cout << ans.size() << "\n";
            for (auto i: ans){
                cout << i.F << " " << i.S << "\n";
            }
        } else {
            cout << "0\n";
        }
        cout << "\n";
    }
    return 0;
}
