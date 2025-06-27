#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;   
    cin >> t;

    int n = t.length();
    int i=n/2;
    int j=n/2;

    string ans = "";
    if(n%2!=0){
        ans += t[n/2];
        i--;
        j++;
        while(i >= 0 && j<=n-1){
            ans += t[j++];
            ans += t[i--];
        }
    }
    
    else{
        i--;
        while(i >= 0 && j<=n-1){
            ans += t[i--];
            ans += t[j++];
        }
    } 

    cout << ans;
}
