#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& x : arr) cin >> x;

    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            arr[j] = arr[j] ^ arr[j + 1];
        }
    }

    cout << arr[0] << "\n";
    return 0;
}



// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(auto& x : arr) cin >> x;

//     int result = 0;
//     for(int i = 0; i < n; ++i) {
//         if((i & (n - 1 - i)) == 0) {
//             result ^= arr[i];
//         }
//     }

//     cout << result << "\n";
// }
