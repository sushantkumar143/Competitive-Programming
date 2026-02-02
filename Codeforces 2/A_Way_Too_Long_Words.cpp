#include<bits/stdc++.h>
using namespace std;

string fun(string s) {
    int n = s.length();
    if(n <= 10) return s;

    string ans = "";
    ans += s[0];
    string temp =  s.substr(1, n-2);
    ans += to_string(temp.length());
    ans += s[n-1];
    return ans;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;

        cout << fun(s) << '\n';
    }
}