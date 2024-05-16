#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> prime_v(int n){
    int rn = 1;
    vector<int> pri;
    bool is_Prime = true;
    vector<int>::iterator iter;


    for(int i=2;i<n+1;i++){
        is_Prime = true;
        for(iter = pri.begin(); iter != pri.end(); iter++){
            if(i%*(iter)==0){
            is_Prime = false;
            continue;
            }
        }
        if(is_Prime==true){
            pri.push_back(i);
        }
    }

    
    return pri;
    
}

int main(){
    int n,max_num;
    max_num = 1;
    cin >> n;
    int pr[n];
    
    for(int i = 0;i<n;i++){
        cin >> pr[i];
        max_num = max(max_num,pr[i]);
    }
    vector<int>::iterator iter;
    vector<int> pri = prime_v(max_num);


    int count = 0;
    for(int i = 0;i<n;i++){
        if(find(pri.begin(),pri.end(),pr[i]) != pri.end()){
            count++;
        }
    }

    cout << count;

}