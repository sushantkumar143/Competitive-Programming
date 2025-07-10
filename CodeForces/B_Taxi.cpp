#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int sm = 0;
    
    while(t--){
        int n;
        cin >> n;
        sm += n;
    }

    int ans = sm%2==0 ? sm/4 : sm/4 + 1;
    cout << ans;
}