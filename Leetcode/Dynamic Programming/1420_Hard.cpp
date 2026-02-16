#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool check(vector<int>& arr, int k) {
//         int cost = 0;
//         int maxi = -1;

//         for(int i=0; i<arr.size(); i++) {
//             if(arr[i] > maxi) {
//                 maxi = arr[i];
//                 cost++;
//             }
//         }
//         return cost == k;
//     }

//     int fun(int n, int m, int k, vector<int>& temp) {
//         if(temp.size() == n) {
//             if(check(temp, k)) return 1;
//             return 0;
//         }

//         int ways = 0;
//         for(int i=1; i<=m; i++) {
//             temp.push_back(i);
//             ways += fun(n, m, k, temp);
//             temp.pop_back();
//         }

//         return ways;
//     }

//     int numOfArrays(int n, int m, int k) {
//         vector<int> temp;
//         return fun(n, m, k, temp);
//     }
// };



class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[51][101][51];

    int solve(int idx, int n, int m, int k, int maxi, int cost) {
        if (idx == n) {
            return cost == k;
        }

        if (dp[idx][maxi][cost] != -1)
            return dp[idx][maxi][cost];

        long long ways = 0;

        for (int val = 1; val <= m; val++) {
            if (val > maxi) {
                ways += solve(idx + 1, n, m, k, val, cost + 1);
            } 
            else {
                ways += solve(idx + 1, n, m, k, maxi, cost);
            }
            ways %= MOD;
        }

        return dp[idx][maxi][cost] = ways;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, m, k, 0, 0);
    }
};