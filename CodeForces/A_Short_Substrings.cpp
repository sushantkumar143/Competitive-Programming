#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        string ans = "";
        ans += s[0];
        for(int i=1; i<n-1; i++){
            if(i%2 == 0){
                ans += s[i];
            }
        }
        ans += s[n-1];

        cout << ans << '\n';
    }
}
