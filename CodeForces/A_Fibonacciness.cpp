#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;

    while (t--) {
        int a1,a2,a4,a5;
        cin >> a1 >> a2 >> a4 >> a5;
        int s1 = a1 + a2;
        int s2 = a4 - a2;
        int s3 = a5 - a4;
        // count frequencies among s1,s2,s3
        int ans = 1;
        if (s1 == s2 && s2 == s3) ans = 3;
        else if (s1 == s2 || s1 == s3 || s2 == s3) ans = 2;
        else ans = 1;
        cout << ans << '\n';
    }
    return 0;
}
