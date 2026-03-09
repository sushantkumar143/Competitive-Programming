#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long, int> dp;

    int fun(long long n) {
        if(n == 1) return 0;
        if(dp.count(n)) return dp[n];

        if(n % 2 == 0)
            return dp[n] = 1 + fun(n / 2);

        return dp[n] = 1 + min(fun(n - 1), fun(n + 1));
    }

    int integerReplacement(int n) {
        return fun((long long)n);
    }
};