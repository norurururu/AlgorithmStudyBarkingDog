#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool comp(const string &a,const string &b){
    if(a.size()>b.size())
    return false;
    if(a.size()<b.size())
    return true;
    int a_sum=0,b_sum=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')
        a_sum+=(a[i]-'0');
        if(b[i]>='0'&&b[i]<='9')
        b_sum+=(b[i]-'0');
    }
    if(a_sum>b_sum){
        return false;
    }
    if(a_sum<b_sum){
        return true;
    }
    for(int j=0;j<a.size();j++){
        if(a[j]>b[j])
        return false;
        if(a[j]<b[j])
        return true;
    }
    return false;
}


int main(){
    string s;
    
    vector <string> s2;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        s2.push_back(s);
    }
    sort(s2.begin(),s2.end(),comp);


    for(int i=0;i<n;i++){
      cout << s2[i]<<"\n";
    }
}