#include <bits/stdc++.h>
using namespace std;

bool search(long long target, vector<long long>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> b(k);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < k; i++) {
        if (search(b[i], a)) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
