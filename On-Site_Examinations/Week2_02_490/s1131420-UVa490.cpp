#include<iostream>
#include<string>
using namespace std;

string s[113];// 題目限制最多 100 行，宣告 113 作為緩衝
int main() {
	cin.tie(0);// 優化輸入輸出速度
	int col = 0, row = 0;
	while (getline(cin, s[col])) {// 讀取每行輸入，直到 EOF
		row = max(row, (int)s[col].size());// 更新最大行長
		col++;// 更新行數
	}
	for (int i = 0; i < row; i++) {// 逐行輸出轉置後的結果
		for (int j = col - 1; j >= 0; j--) {// 從最後一行開始輸出
			if (i >= s[j].size()) cout << " ";// 如果當前行長不足，輸出空格
			else cout << s[j][i];// 否則輸出對應的字元
		}
		cout << "\n";// 每行結束後換行
	}
	
}