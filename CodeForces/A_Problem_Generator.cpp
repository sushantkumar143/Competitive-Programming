#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;

        vector<int> have(7, 0);
        for (char ch : a) {
            have[ch - 'A']++;
        }

        int needToCreate = 0;
        for (int i = 0; i < 7; i++) {
            needToCreate += max(0, m - have[i]);
        }

        cout << needToCreate << "\n";
    }
}
