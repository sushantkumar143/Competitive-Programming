#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ans = n/2;
    cout << ans << '\n';
    if(n%2 == 0) {
        for(int i=0; i<ans; i++){
            cout << 2 << " ";
        }
    }
    else{
        for(int i=0; i<ans-1; i++){
            cout << 2 << " ";
        }
        cout << 3;
    }
}