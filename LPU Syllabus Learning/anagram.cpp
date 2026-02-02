#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if(s1 == s2) cout << "It is an Anagram";
    else cout << "It is not an Anagram";
}