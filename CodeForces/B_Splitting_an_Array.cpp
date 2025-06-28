#include <bits/stdc++.h>
using namespace std;

bool canSplit(long long mid, int k, const vector<int>& arr) {
    long long cnt = 1; 
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (sum + arr[i] > mid) {
            cnt++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }

    return cnt <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    long long totalSum = 0;
    int maxElem = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
        maxElem = max(maxElem, arr[i]);
    }

    long long left = maxElem;
    long long right = totalSum;
    long long ans = totalSum;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canSplit(mid, k, arr)) {
            ans = mid;
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    cout << ans << '\n';
}
