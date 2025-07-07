#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

string s;
vector<int> dp;

int countWays(int i) {
    if (i == s.size()) return 1;
    if (dp[i] != -1) return dp[i];

    long long ways = countWays(i + 1);

    if (i + 1 < s.size() && s[i] == s[i + 1] && (s[i] == 'u' || s[i] == 'n')) {
        ways = (ways + countWays(i + 2)) % MOD;
    }

    return dp[i] = ways;
}

int main() {
    cin >> s;

    for (char c : s) {
        if (c == 'm' || c == 'w') {
            cout << 0 << endl;
            return 0;
        }
    }

    dp.assign(s.size() + 1, -1);
    cout << countWays(0) << endl;
    return 0;
}
