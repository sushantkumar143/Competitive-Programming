#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0, maxLen = 0;
    int left = 0;

    for(int right = 0; right < n; right++) {
        sum += arr[right];

        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << '\n';
    return 0;
}
