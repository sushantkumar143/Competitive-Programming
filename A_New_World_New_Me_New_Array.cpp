#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k, p;
        cin >> n >> k >> p;

        k = abs(k);
        if(n*p < k) {
            cout << -1 << '\n';
            continue;
        }

        int cnt = 0;
        int temp = 0;
        while(temp+p < k) {
            temp += p;
            cnt++;
        }
        
        if(temp != k) cnt++;
        cout << cnt << '\n';
    }
}