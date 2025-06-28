#include <bits/stdc++.h>
using namespace std;

int countInRange(vector<int>& arr, int l, int r) {
    int lower = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
    int upper = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
    return upper - lower;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int left, right;
        cin >> left >> right;
        cout << countInRange(arr, left, right) << " ";
    }
}
