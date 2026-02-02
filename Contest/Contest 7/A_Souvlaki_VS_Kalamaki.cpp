#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    bool win = true;    
    for (int i=1; i<n-1; i += 2) {
        if (arr[i] != arr[i + 1]) {
            win = false;
            break;
        }
    }

    if (win) {
        cout << "YES" << endl;
    } 
    
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
     
}