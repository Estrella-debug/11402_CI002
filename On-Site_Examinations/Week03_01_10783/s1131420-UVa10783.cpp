#include <iostream>
using namespace std;

int main() {
	int T, i, j;
	cin >> T;
	for (int Case = 1; Case <= T; Case++) {// 讀取測試案例數 T
		cin >> i>>j;
		//在j前面上誤打成","所以產生了bug 只輸入i 沒有將j正確輸入
		int sum = 0;
		if (i % 2 == 0) {// 如果 i 是偶數，則從下一個奇數開始
			i += 1;
		}
		for (int x = i; x <= j; x += 2) {// 從 i 開始，每次增加 2，直到 j
			sum += x;
		}
		cout << "Case " << Case << ": " << sum << "\n";
	}
	return 0;
}