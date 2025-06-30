#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long s;
    cin >> n >> s;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int left = 0;
    long long totalLengthSum = 0;

    for (int right = 0; right < n; right++) {
        sum += a[right];

        while (sum > s) {
            sum -= a[left];
            left++;
        }
        
        long long len = right - left + 1;
        totalLengthSum += (len * (len + 1)) / 2;
    }

    cout << totalLengthSum << endl;
    return 0;
}
