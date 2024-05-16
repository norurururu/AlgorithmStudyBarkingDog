#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a=1;
    for (int i=0;i<k;i++){
        a=a*(n-i)/(i+1);
    }
    cout << a;
    return 0;
}