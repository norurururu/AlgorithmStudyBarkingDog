#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    quickSort(arr, 0, arr.size() - 1);
    for(auto a : arr) cout << a << " ";
    
}
