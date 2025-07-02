#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    while(n--){
        long a,b,c;
        cin >> a >> b >> c;
        long long ans = (long long)(pow(pow(a, b), c)) % (long long)(1e9 + 11);
        cout << ans << '\n';
    }
}