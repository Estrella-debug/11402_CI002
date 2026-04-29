#include<iostream>
using namespace std;

int main(){
    int T,n;
    cin>>T;
    for(int Case =1;Case<=T;Case++){
        cin>>n;
        int x, mn =100,mx =0;
        for(int i =0;i<n;i++){
            cin>>x;
            if(x>mx) mx =x;
            if(x<mn)mn =x;
        }
        cout<<(mx-mn)*2<<"\n";
    }
    return 0;
}

