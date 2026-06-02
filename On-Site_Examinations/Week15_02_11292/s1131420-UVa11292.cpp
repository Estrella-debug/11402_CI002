#include<iostream>
#include<algorithm>
using namespace std;
int n, m, ans, cnt, head[20010], knight[20010];
int main(){
	while(cin>>n>>m && (n!=0 || m!=0)){
		ans=0, cnt=0;
		for(int i=0 ; i<n ; i++){
			cin>>head[i];
		}
		for(int i=0 ; i<m ; i++){
			cin>>knight[i];
		}
		// 如果騎士數量比龍頭數量還小，必定不能擊敗
		if(n>m){
			cout<<"Loowater is doomed!\n";
			continue;
		}
		sort(head, head+n);
		sort(knight, knight+m);
		for(int i=0, j=0 ; i<n && j<m && cnt!=n ; ){
			if(knight[j] >= head[i]){
				ans += knight[j];
				i++, j++, cnt++;
			}
			else{
				j++;
			}
		}
		if(cnt != n){
			cout<<"Loowater is doomed!\n";
		}
		else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
