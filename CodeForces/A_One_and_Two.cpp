#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while(t--) {
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for(int i = 0; i < n; i++) cin >> arr[i];

//         long long total = 1;
//         for(int x : arr) total *= x;

//         long long prefix = 1;
//         int ans = -1;

//         for(int i = 0; i < n-1; i++) { 
//             prefix *= arr[i];
//             long long right = total / prefix;
//             if(prefix == right) {
//                 ans = i + 1;
//                 break;
//             }
//         }

//         cout << ans << "\n";
//     }
// }


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        int count2_total = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] == 2) count2_total++;
        }

        int count2_prefix = 0;
        int ans = -1;

        for(int i = 0; i < n-1; i++) {
            if(arr[i] == 2) count2_prefix++;

            if(count2_prefix == count2_total - count2_prefix) {
                ans = i + 1; 
                break;
            }
        }

        cout << ans << "\n";
    }
}
