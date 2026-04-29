#include<iostream>
#include<string>
using namespace std;

int main(){
    int x,y;
    while(cin>>x){
        if(x==0)break;
        string T ="";
        y=x;
        int cnt =0;
        while(y){
            cnt += (y & 1);
            T += '0'+ (y & 1);
            y>>= 1;
        }
        reverse(T.begin(),T. end());
        cout<<"The parity of "<<T<<" is "<<cnt<<" (mod 2).\n";
    }
    return 0;
}
