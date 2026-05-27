#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	while (cin >> n && n) {

		priority_queue<int, vector<int>, greater<int>> line;
		int input, temp, result = 0;

		while (n--) cin >> input, line.emplace(input);
		
		while (line.size() > 1) {
			temp = line.top(), line.pop();
			temp += line.top(), line.pop();
			line.emplace(temp);
			result += temp;
		}

		cout << result << "\n";
	}

	return 0;
}