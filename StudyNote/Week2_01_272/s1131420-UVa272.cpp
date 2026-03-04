#include<iostream>
#include<string>
using namespace std;

string s;
int cnt;//計數器預設為0
int main() {
	while (getline(cin, s)) {//使用getline讀取整行
		for (int i = 0; i < s.length(); i++) {//逐字元讀取
			if (s[i] == '\"') {//當讀取到引號時
				if (cnt % 2 == 0) {//當cnt為偶數時，輸出``
					cout << "``";
				}
				else {//當cnt為奇數時，輸出''
					cout << "''";
					//原在這打了cnt++ ,造成了上、下引號都使用了 `` 所以 WA;
				}
				cnt++;//經過訂正cnt++,放於此處才可分辨出上、下引號
			}
			else cout << s[i];//當讀取到非引號字元時，直接輸出
		}
		cout << "\n";//每行結束後換行
	}
    return 0;
}
