#include<iostream>
#include<cmath>
#include <algorithm>
#include <vector>


using namespace std;

int num;

int check(int arr[],int find){
    int is_find = 0;
    int max = num;
    int min = 0;
    int i = (max+min)/2;
    while (1)
    {
        if(find == arr[i]){
            is_find = 1;
            break;
        }
        else if(find > arr[i]){
            min = i;
            i = (max+min)/2;
        }
        else if(find < arr[i]){
            max = i;
            i = (max+min)/2;
        }
        
        if(min==max||min+1==max){
            if(find == arr[i]){
                is_find = 1;
                }
            break;
        }
    }

    return is_find;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;
    int ans[num];
    for (int i = 0; i < num; i++)
    {
        cin >> ans[i];
    }
    sort(ans,ans+num);

    int count;
    cin >> count;
    int n;
    for (int i = 0; i < count; i++)
    {
        cin >> n;
        cout << check(ans,n)<<" ";
    }
return 0;

    

}