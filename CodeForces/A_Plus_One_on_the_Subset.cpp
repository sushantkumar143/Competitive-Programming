#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto &x : arr){
            cin >> x;
            maxi = max(maxi, x);
            mini = min(mini, x);
        }

        cout << maxi-mini << '\n';
    }
}