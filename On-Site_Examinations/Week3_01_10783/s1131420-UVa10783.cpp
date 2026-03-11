#include<bits/stdc++.h>
using namespace std;

int main() {
	int T, i, j;
	cin >> T;
	for (int Case = 1; Case <= T; Case++) {
		cin >> i>>j;
		//在j前面上誤打成","所以產生了bug 只輸入i 沒有將j正確輸入
		int sum = 0;
		if (i % 2 == 0) {
			i += 1;
		}
		for (int x = i; x <= j; x += 2) {
			sum += x;
		}
		cout << "Case " << Case << ": " << sum << "\n";
	}
	return 0;
}