#include <iostream>
#include <stack>

using namespace std;

string in, target;

void dfs(stack<char> starts, string results, stack<char> stacks, string out, int n)
{
    if (n == in.size() * 2) {
        if (results == target) cout << out << "\n";
        return;
    }

    if (starts.size() > 0) {
        auto tmp1 = stacks, tmp2 = starts;
        tmp1.emplace(tmp2.top());
        tmp2.pop();
        dfs(tmp2, results, tmp1, out + (n ? " i" : "i"), n + 1);
    }

    if (stacks.size() > 0 && stacks.top() == target[results.size()]) {
        auto tmp1 = stacks;
        tmp1.pop();
        dfs(starts, results + stacks.top(), tmp1, out + " o", n + 1);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> in >> target) {

        stack<char> starts, stacks;
        for (int i = in.size() - 1; i >= 0; --i) starts.emplace(in[i]);

		cout << "[\n";
        if (in.size() == target.size()) dfs(starts, "", stacks, "", 0);
		cout << "]\n";
	}

	return 0;
}