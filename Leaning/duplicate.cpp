#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= arr[i];
        ans ^= i+1;
    }
    // for(int i=1; i<n; i++){
    //     ans ^= i;
    // }
    cout << ans;
}