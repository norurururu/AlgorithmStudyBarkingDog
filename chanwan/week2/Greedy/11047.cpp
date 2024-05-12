#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n>> k;
    vector <int> v;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a<=k){
            v.push_back(a);
        }

    }
    vector <int>::iterator st,en;
    en = v.end()-1;
    st = v.begin()-1;
    int answer =0;
    for(auto it=en;it!=st;it--){
        answer+=k/(*it);
        k = k%*it;
    }
    cout << answer;
}