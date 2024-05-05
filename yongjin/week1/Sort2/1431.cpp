#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int digitSum(string str) {
    int sum = 0;
    for (char ch : str) {
        if (isdigit(ch)) sum += ch - '0';
    }
    return sum;
}

bool compare(string str1, string str2) {
    if (str1.length() != str2.length()) return str1.length() < str2.length();
    if (digitSum(str1) != digitSum(str2)) return digitSum(str1) < digitSum(str2);
    return str1 < str2;
}

int main() {
    int n;
    cin >> n;
    vector<string> serials(n);
    for (int i = 0; i < n; i++) {
        cin >> serials[i];
    }
    sort(serials.begin(), serials.end(), compare);
    for (string serial : serials) {
        cout << serial << '\n';
    }
    return 0;
}
