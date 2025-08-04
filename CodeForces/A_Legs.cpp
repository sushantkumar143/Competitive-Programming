#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    while(n--){
        int legs;
        cin >> legs;

        int ans = 0;
        if(legs>=4){
            ans += legs/4;
            legs %= 4;
            ans += legs/2;
        }
        else ans += legs/2;
        cout << ans << '\n';
    }
}