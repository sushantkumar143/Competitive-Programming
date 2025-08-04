#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int mini = INT_MAX;
        int ans = 1;
        int cnt = 0;

        for(auto &x : arr){
            cin >> x;
            mini = min(mini, x);
        }

        for(int i : arr){
            if(!cnt && i == mini){
                ans *= (i+1);
                cnt = 1;
            }
            else ans *= i;
        }

        cout << ans << '\n';
    }
}