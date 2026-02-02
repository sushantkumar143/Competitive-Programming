#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long sm = 0;
    long long ans = INT_MIN;

    for(int i=0; i<n; i++) {
        long long x;
        cin >> x;

        sm = max(x, sm+x);
        ans = max(ans, sm);
    }

    cout << ans;
}