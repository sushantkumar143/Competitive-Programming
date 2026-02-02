#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, 1});
        a.push_back({y, -1});
    }

    sort(a.begin(), a.end());
    
    int ans = 0;
    int sm = 0;

    for(auto x : a) {
        sm += x.second;
        ans = max(ans, sm);
    }

    cout << ans;
    return 0;
}