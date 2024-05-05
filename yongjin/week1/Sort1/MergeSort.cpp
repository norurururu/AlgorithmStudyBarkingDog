#include <iostream>
using namespace std;

int sorted[6];
void merge(int arr[],int left, int mid, int right){
    int i=0;
    int k=0;
    int j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            sorted[k]=arr[i];
            i++;k++;
        }else{
            sorted[k]=arr[j];
            j++;k++;
        }
    }
    if(i>mid){
        while(j<=right){
            sorted[k]=arr[j];
            k++;j++;
        }
    }
    if(j>right){
        while(i<=mid){
            sorted[k]=arr[i];
            k++;i++;
        }
    }
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}


int main(){
    int arr[]={12,11,13,5,6,7};
    int arrsize = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,5);
    for(auto s:sorted) cout<<s<<" ";
}