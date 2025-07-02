#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool canMake(ll time, vector<int>& machines, ll t) {
    ll total = 0;
    for (int k : machines) {
        total += time / k;
        if (total >= t) return true; 
    }
    return total >= t;
}

int main() {
    int n;
    ll t;
    cin >> n >> t;

    vector<int> machines(n);
    for (int i = 0; i < n; ++i)
        cin >> machines[i];

    ll left = 1, right = 1e18;
    ll answer = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (canMake(mid, machines, t)) {
            answer = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
