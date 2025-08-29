#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> arr1(n), arr2(m);
        for (int &x : arr1) cin >> x;
        for (int &x : arr2) cin >> x;

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int i = 0, j = m - 1;
        int cnt = 0;

        while (i < n && j >= 0) {
            if (arr1[i] + arr2[j] <= k) {
                cnt += (j + 1);
                i++;
            } 
            else {
                j--;
            }
        }

        cout << cnt << '\n';
    }
}
