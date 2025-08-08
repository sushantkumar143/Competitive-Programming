#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<string, int> freq;

    for (int i = 1; i < n; i++) {
        string t = string(1, s[i - 1]) + string(1, s[i]);
        freq[t]++;
    }

    int temp = -1;
    string ans;
    for (auto& x : freq) {
        if (x.second > temp) {
            temp = x.second;
            ans = x.first;
        }
    }

    cout << ans;
}
