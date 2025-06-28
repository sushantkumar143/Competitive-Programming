#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<pair<long long, long long>> movies(n);
    for (long long i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    long long ans = 0;
    long long currEnd = 0;

    for (long long i = 0; i < n; i++) {
        if (movies[i].first >= currEnd) {
            ans++;
            currEnd = movies[i].second;
        }
    }

    cout << ans << '\n';
}
