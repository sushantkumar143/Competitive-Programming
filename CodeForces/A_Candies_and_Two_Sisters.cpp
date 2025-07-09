#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;
        long long ans = n%2!=0 ? n/2 : n/2-1;
        cout << ans << '\n';
    }
}