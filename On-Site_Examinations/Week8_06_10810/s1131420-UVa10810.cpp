#include<iostream>
using namespace std;

long long int counter;
int ans[500005]={0};

void Merge(int* input, int left, int mid, int right){
    int idxl=left,idxr=mid+1;

    for(int i=0;i<=right-left;++i){
        if(idxl>mid){
            /* Left array run out */
            ans[i]=input[idxr++];
            continue;
        }
        if(idxr>right){
            /* Right array run out */
            ans[i]=input[idxl++];
            continue;
        }
        if(input[idxl]<=input[idxr]){
            /* Copy left array value */
            ans[i]=input[idxl++];
        }else{
            /* Copy right array value */
            counter += (mid-idxl+1);
            ans[i]=input[idxr++];
        }
    }

    /* Copy to original array */
    for(int i=0;i<=right-left;++i){
        input[left+i]=ans[i];
    }
}

void mergeSort(int* input, int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        /* Split left array */
        mergeSort(input, left, mid);
        /* Split right array */
        mergeSort(input, mid+1, right);
        /* Merge left and right array */
        Merge(input, left, mid, right);
    }
}

int main(){
    int kase;
    while(1){
        cin >> kase;
        if(kase==0)
            break;
        else{
            int input[500005]={0};
            for(int i=0;i<kase;++i){
                cin >> input[i];
            }
            counter = 0;
            mergeSort(input,0,kase-1);
            cout << counter<< endl;
        }
    }
    return 0;
}