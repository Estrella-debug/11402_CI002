#include<iostream>
#include <string>

using namespace std;
int dp[1005][1005];
string s, t;

int main(){
	while(getline(cin, s) && getline(cin, t)){
		for(int i=1 ; i<=s.size() ; i++){
			for(int j=1 ; j<=t.size() ; j++){
				if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout<<dp[s.size()][t.size()]<<"\n";
	}
	return 0;
}
