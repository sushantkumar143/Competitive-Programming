#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/find-optimum-operation4504/1

// class Solution {
//   public:
//     long long fun(long long cur, int n, vector<long long>& dp) {
//         if (cur == n) return 0;
//         if (cur > n) return 1e18;

//         if (dp[cur] != -1) return dp[cur];

//         long long add = 1 + fun(cur + 1, n, dp);
//         long long twice = 1e18;

//         if (cur != 0)
//             twice = 1 + fun(cur * 2, n, dp);

//         return dp[cur] = min(add, twice);
//     }

//     int minOperation(int n) {
//         vector<long long> dp(n + 1, -1);
//         return fun(0, n, dp);
//     }
// };


class Solution {
  public:
    int minOperation(int n) {
        int steps = 0;
        while (n > 0) {
            if (n % 2 == 0)
                n /= 2;
            else
                n -= 1;
            steps++;
        }
        return steps;
    }
};