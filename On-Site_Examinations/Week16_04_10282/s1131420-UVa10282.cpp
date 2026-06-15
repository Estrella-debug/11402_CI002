#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	map<string, string> dict;
	string input, key, value;
	stringstream ss;

	while (getline(cin, input) && input != "") {
		ss.clear();
		ss << input;
		ss >> value >> key;
		dict[key] = value;
	}
	while (getline(cin, input)) cout << (dict.find(input) != dict.end() ? dict[input] : "eh") << endl;

	return 0;
}