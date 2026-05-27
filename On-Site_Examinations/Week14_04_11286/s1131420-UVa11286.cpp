#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, max_num, total;
	map<string, int> course;
	vector<string> class_num;
	string input, line;

	while (cin >> n && n != 0) {
		max_num = 0;
		total = 0;
		course.clear();	

		while (n--) {
			line.clear();
			class_num.clear();
			for (int i = 0; i < 5; ++i) cin >> input, class_num.push_back(input);
			sort(class_num.begin(), class_num.end());
			for (int i = 0; i < 5; ++i) line += class_num[i];
			++course[line];
		}
		
		for (auto it = course.begin(); it != course.end(); ++it)
			if (it->second > max_num) max_num = it->second;
		for (auto it = course.begin(); it != course.end(); ++it)
			if (it->second == max_num) total += max_num;
			
		cout << total << endl;
	}
	
	return 0;
}