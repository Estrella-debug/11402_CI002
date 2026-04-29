#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int p1=m-1;
        int p2=n-1;
        int tail=m+n-1;
        while (p1>=0 && p2>=0){
            if (nums1[p1]<=nums2[p2]){
                nums1[tail]=nums2[p2];
                tail-=1;
                p2-=1;
            }
            else{
                nums1[tail]=nums1[p1];
                tail-=1;
                p1-=1;
            }
        }
        while (p2>=0){
            nums1[tail]=nums2[p2];
            tail-=1;
            p2-=1;
        }
    }
};

int main(){
    vector<int>nums1={1,2,3,0,0,0};
    vector<int>nums2={2,5,6};
    int m=3;
    int n=3;
    Solution res;
    res.merge(nums1,m,nums2,n);
    for (int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    return 0;
}

