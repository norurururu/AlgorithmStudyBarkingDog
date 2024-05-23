#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n;
    set<string> se;
    cin >> n;
    string a,b;
    for(int i=0;i<n;i++){
        cin >> a >>b;
        if(b=="enter"){
            se.insert(a);
        }
        else{
            se.erase(a);
        }
    }
    //sort(se.begin(),se.end());
    set<string>::iterator it;
    for(it=se.end();it!=se.begin();){
        it--;
        cout << *it <<"\n";
    }
    return 0;
}