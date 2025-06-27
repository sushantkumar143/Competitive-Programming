#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int times;
    cin >> times;

    while(times--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int diff = INT_MAX;
        for(int i=1; i<n; i++){
            diff = min(diff, arr[i]-arr[i-1]);
        }
        int ans = (diff/2) + 1;
        cout << ans << "\n";
    }
}