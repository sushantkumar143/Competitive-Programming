#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int& x : arr) {
        cin >> x;
    }
    if(n == 0) {
        cout << 0;
        return 0;
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    int last = arr[0];

    for(int i=1; i<n; i++) {
        if(arr[i] != last) {
            cnt++;
            last = arr[i];
        }
    }

    cout << cnt;
    return 0;
}