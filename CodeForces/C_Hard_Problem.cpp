#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int ans = 0;
        int row1 = m;
        int row2 = m;

        if(row1 < a){
            ans += row1;
            row1 = 0;
        }
        else {
            ans += a;
            row1 -= a;
        }

        if(row2 < b){
            ans += row2;
            row2 = 0; 
        }
        else {
            ans += b;
            row2 -= b;
        }

        if(c < row1){
            ans += c;
            row1 -= c;
            c = 0;
        }
        else{
            ans += row1;
            c -= row1;
            row1 = 0;
        }

        if(c < row2){
            ans += c;
            row2 -= c;
            c = 0;
        }
        else{
            ans += row2;
            c -= row2;
            row2 = 0;
        }

        cout << ans << '\n';
    }
}
