#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int diff1 = abs(1-a);
        int diff2 = abs(1-c) + abs(c-b);
        
        if(diff1 < diff2) cout << 1 << '\n';
        else if(diff1 > diff2) cout << 2 << '\n';
        else cout << 3 << '\n';
    }
}