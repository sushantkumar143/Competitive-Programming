// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int times;
//     cin >> times;

//     while(times--){
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for(int i=0; i<n; i++){
//             cin >> arr[i];
//         }
//         int diff = INT_MAX;
//         for(int i=1; i<n; i++){
//             diff = min(diff, arr[i]-arr[i-1]);
//         }
//         int ans = (diff/2) + 1;
//         cout << ans << "\n";
//     }
// }



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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (!sorted) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n - 1; i++) {
            long long diff = a[i + 1] - a[i];
            long long ops = diff / 2 + 1;
            ans = min(ans, ops);
        }

        cout << ans << "\n";
    }
    return 0;
}
