#include<iostream>
using namespace std;
int main() {
	int a1, a2;
	while (cin >> a1 >> a2) {//輸入兩個值
		int carry = 0, cnt = 0;
		if (a1 == 0 && a2 == 0) break;//當a1,a2都為0時break
		while (a1 > 0 || a2 > 0) {//當其中一值大於0時繼續執行
			int tmp = a1 % 10 + a2 % 10 + carry;//將a1,a2的個位數相加再加上carry
			if (tmp >= 10) {//如果tmp>=10,carry為tmp/10的商，cnt加1
				carry = tmp / 10;
				cnt++;
			}
			else {
				carry = 0;//如果tmp<10,carry=0
			}
			a1 /= 10;//將a1,a2除以10,去掉個位數
			a2 /= 10;
		}
		if (cnt == 0)cout << "No carry operation.\n";
		else if (cnt == 1)cout << "1 carry operation.\n";
		else cout << cnt << " carry operations.\n";
	}
	return 0;
}