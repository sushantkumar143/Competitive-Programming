#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int& x : arr) cin >> x;

        bool flag = false;
        for(int i=1; i<n; i++) {
            if(abs(arr[i-1] - arr[i]) != 5 && abs(arr[i-1] - arr[i]) != 7) {
                flag = true;
                break;
            }
        }

        if(!flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
