#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
int a;

cin >> a;
for(int i=0;i<a;i++){
multiset <int> s;
int b,n;
char q;
cin >> b;
for(int j=0;j<b;j++){
cin >> q >> n;
if(q=='I'){
    s.insert(n);
}
else{
    if(s.empty())continue;
    if(n==1){
        multiset<int>::iterator it=s.end();
        it--;
        s.erase(it);
    }
    else{
        s.erase(s.begin());
    }
    
}
}

if(s.empty())
cout << "EMPTY"<<"\n";
else{
    multiset<int>::iterator it=s.end();
        it--;
    cout << *it<<" "<<*(s.begin())<<"\n";
}
}
return 0;
}