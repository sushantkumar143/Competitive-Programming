#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int maxLen = 1, curr = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                curr = 1;
            }
            maxLen = max(maxLen, curr);
        }

        cout << maxLen + 1 << "\n";
    }
    return 0;
}
