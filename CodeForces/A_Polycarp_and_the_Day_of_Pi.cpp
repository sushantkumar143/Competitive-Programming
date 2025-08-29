#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string PI = "314159265358979323846264338327";
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        string s; 
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < (int)s.size() && i < (int)PI.size(); ++i) {
            if (s[i] == PI[i]) ++cnt;
            else break;
        }
        cout << cnt << "\n";
    }
    return 0;
}
