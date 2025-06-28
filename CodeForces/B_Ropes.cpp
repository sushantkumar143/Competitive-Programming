#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& arr, double mid, int k) {
    int cnt = 0;
    for(int length : arr) {
        cnt += int(length / mid); 
    }
    return cnt >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        maxi = max(arr[i], maxi);
    }

    double left = 0.0, right = maxi;
    double ans = 0.0;

    while(right - left > 1e-7) { 
        double mid = (left + right) / 2;
        if(solve(arr, mid, k)) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(10) << ans << "\n";
}
