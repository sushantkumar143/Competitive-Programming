#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int last = 0, maxRounds = 0;
    for(int i = 0; i < n; i++) {
        int rounds = (a[i] + m - 1) / m; 
        if(rounds >= maxRounds) {
            maxRounds = rounds;
            last = i + 1; 
        }
    }
    cout << last << endl;
    return 0;
}
