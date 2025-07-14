#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = a ^ b ^ c;
        cout << ans << '\n';
    }
}