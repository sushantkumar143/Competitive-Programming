#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > s && left <= right) {
            sum -= arr[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}
