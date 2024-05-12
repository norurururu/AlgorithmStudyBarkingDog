#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n,a,b,sum;
    cin >> m >> n;
    int s[m+1];
    s[0]=0;
    cin >> s[1];

    for(int i=2;i<=m;i++){
        cin >> a;
        s[i]=s[i-1]+a;
    }

    for(int i=0;i<n;i++){
        cin >> a >> b;
        sum = s[b]-s[a-1];
        cout << sum <<"\n";
    }
    
    return 0;
}