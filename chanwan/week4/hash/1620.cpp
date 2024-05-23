#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >>m;
    string s;
    unordered_map<string,int> um1;
    unordered_map<int,string> um2;

    for(int i=0;i<n;i++){
        cin >> s;
        um1.insert({s,i+1});
        um2.insert({i+1,s});
    }

    unordered_map<string,int>::iterator st1;
    unordered_map<int,string>::iterator st2;


    int a;
    for(int i=0;i<m;i++){
        cin >> s;
        if(47<s[0]&&s[0]<58){
            a = stoi(s);
            st2 = um2.find(a);
            cout << (*st2).second <<"\n";
        }
        else{
            st1 = um1.find(s);
            cout << (*st1).second <<"\n";
        }
    }

    return 0;
}