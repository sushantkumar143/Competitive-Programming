#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n+1), p(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        p[i] = p[i-1] + x[i];
    }
    deque<int> dq;
    long long ans = LLONG_MIN;
    for(int r = a; r <= n; r++) {
        while(!dq.empty() && dq.front() < r - b)
            dq.pop_front();
        int newIdx = r - a;
        while(!dq.empty() && p[dq.back()] >= p[newIdx])
            dq.pop_back();
        dq.push_back(newIdx);
        ans = max(ans, p[r] - p[dq.front()]);
    }

    cout << ans << "\n";
    return 0;
}
