#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--) {
        int x, k;
        cin >> x >> k;

        if(x%k != 0) cout << 1 << '\n' << x << '\n';
        else cout << 2 << '\n' << x-1 << '\n' << 1 << '\n';
    }
}