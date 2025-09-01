#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> g(n);
        long long S = 0;
        for (int i = 0; i < n; ++i) { cin >> g[i]; S += g[i]; }
        sort(g.begin(), g.end()); // non-decreasing
        
        if (n == 2) {
            cout << max(g[0], g[1]) << "\n";
            continue;
        }
        
        long long twoLargestSum = g[n-1] + g[n-2];
        long long halfCeil = (S + 1) / 2; // ceil(S/2)
        cout << max(twoLargestSum, halfCeil) << "\n";
    }
    return 0;
}
