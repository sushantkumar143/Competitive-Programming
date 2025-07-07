#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    while(n--){
        long long d, k;
        cin >> d >> k;
        long long ans = (d%k)==0 ? 0 : k - (d%k);
        cout << ans << '\n';
    }
}
