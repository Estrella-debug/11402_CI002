#include <iostream>
using namespace std;
int main() {
	int x, y;
	while (cin >> x >> y) {//輸入x和y，直到EOF
		int max_ = 0;
		for (int n = min(x, y); n <= max(x, y); n++) {//從x和y中較小的數開始，直到較大的數
			int n1 = n, count = 1;//
			while (n1 != 1) {//n=1跳出
				if (n1 % 2 != 0)//n1為奇數
					n1 = 3 * n1 + 1;//n1為偶數
				else n1 /= 2;
				count++;
			}
			max_ = max(max_, count);//更新最大值
		}
		cout << x << " " << y << " " << max_ << endl;
	}

}