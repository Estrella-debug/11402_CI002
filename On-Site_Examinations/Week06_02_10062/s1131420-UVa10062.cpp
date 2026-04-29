#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
#define pii pair<int,int>

bool cmp(pii x, pii y){
    if (x.first != y.first) return x.first < y.first;
    else return x.second > y.second;
}

int main(){
    string s;
    while(getline(cin,s)){
        pii x[256];
        for(int i=0;i<256;i++){
        x [i] ={0,i};
        }
        for(int i=0;i<s.size();i++){
        x[(int)s[i]].first++;
        }
        sort(x,x+256,cmp);
        for(auto i:x){
            if(i.first>0)cout<<i.second<<" "<<i.first<<endl;
        }
        cout<<endl;
    }
    return 0;
}
