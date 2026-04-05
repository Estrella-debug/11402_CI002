#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int M, N;
    cin >> M >> N;
    vector<int> add(M), get(N);
    for (int i = 0; i < M; ++i) cin >> add[i];
    for (int i = 0; i < N; ++i) cin >> get[i];

    multiset<int> ms;
    auto it = ms.begin();
    int get_idx = 0;

    for (int i = 0; i < M; ++i) {
        ms.insert(add[i]);
        // 插入元素後，如果該元素小於當前第k小的元素，迭代器需左移
        if (it != ms.end() && add[i] < *it) {
            --it;
        }

        // 處理當前的 Get 操作
        while (get_idx < N && get[get_idx] == i + 1) {
            if (it == ms.end()) it = ms.begin();
            else ++it;
            cout << *it << endl;
            get_idx++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t > 0) cout << endl; // 題目通常要求範例間有空行
    }
    return 0;
}
