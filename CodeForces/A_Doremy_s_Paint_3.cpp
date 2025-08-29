#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        map<int,int> freq;
        for (int x : a) freq[x]++;

        if (freq.size() > 2) {
            cout << "No\n";
            continue;
        }
        if (freq.size() == 1) {
            cout << "Yes\n";
            continue;
        }

        vector<int> counts;
        for (auto &p : freq) counts.push_back(p.second);
        sort(counts.begin(), counts.end());

        if (n % 2 == 0) {
            if (counts[0] == n/2 && counts[1] == n/2)
                cout << "Yes\n";
            else
                cout << "No\n";
        } 
        else {
            if ((counts[0] == n/2 && counts[1] == n/2 + 1) ||
                (counts[1] == n/2 && counts[0] == n/2 + 1))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
