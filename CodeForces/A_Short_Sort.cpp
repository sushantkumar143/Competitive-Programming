#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        string s1 = s;
        swap(s1[0], s1[1]);
        string s2 = s;
        swap(s2[1], s2[2]);
        string s3 = s;
        swap(s3[0], s3[2]);
        if(s == "abc" || s1 == "abc" || s2 == "abc" || s3 == "abc") cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
