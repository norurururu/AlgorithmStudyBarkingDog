#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr);
    int n,m;
    cin >> n;
    int min,max;
    vector <int> v1;
    vector <int> v2;
    int a,b;
    cin >> a;
    v1.push_back(a);
    min = a;
    max = a;
    for(int i=1;i<n;i++){
        cin >> a;
        v1.push_back(a);
        if(a>max){
            max =a;
        }
        if(a<min){
            min =a;
        }
    }
    int len = max-min+1;
    int l2[len] = {0,};
    for(int i=0;i<n;i++){
        l2[v1[i]-min]++;
    }

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> b;

        v2.push_back(b);
    }

    
    for(int i=0;i<m;i++){
        if(v2[i]>max||v2[i]<min){
            cout << "0" << " ";
        }
        else{
            cout <<l2[v2[i]-min]<<" ";
        }

    }
    return 0;
}