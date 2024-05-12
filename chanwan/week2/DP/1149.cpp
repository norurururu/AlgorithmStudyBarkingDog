#include <iostream>

using namespace std;

int main(){
    int rgb[3] = {0,0,0};
    int n;
    int s1,s2,s3;
    int n1,n2,n3;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> n1 >> n2 >> n3;
        s1= n1+min(rgb[1],rgb[2]);
        s2= n2+min(rgb[0],rgb[2]);
        s3= n3+min(rgb[0],rgb[1]);
        rgb[0]= s1;
        rgb[1]= s2;
        rgb[2]= s3;
    }
    int answer = min(min(rgb[0],rgb[1]),rgb[2]);
    cout << answer;
    return 0;


}