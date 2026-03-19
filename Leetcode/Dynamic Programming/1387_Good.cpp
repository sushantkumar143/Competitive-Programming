#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int fun(int n) {
//         if(n == 1) return 0;

//         int even = 0;
//         int odd = 0;
//         if(n%2 == 0) even = 1 + fun(n/2);
//         else odd = 1 + fun(3*n + 1);

//         return even+odd;
//     }

//     int getKth(int lo, int hi, int k) {
//         priority_queue<pair<int, int>> pq;

//         while(lo <= hi) {
//             int power = fun(lo);
//             if(pq.size() < k) pq.push({power, lo});
//             else if(pq.top().first > power) {
//                 pq.pop();
//                 pq.push({power, lo});
//             }
//             lo++;
//         }

//         return pq.top().second;
//     }
// };



// class Solution {
// public:
//     unordered_map<int,int> memo;

//     int power(int x){
//         if(x == 1) return 0;
//         if(memo.count(x)) return memo[x];

//         if(x % 2 == 0)
//             return memo[x] = 1 + power(x/2);
//         else
//             return memo[x] = 1 + power(3*x + 1);
//     }

//     int getKth(int lo, int hi, int k) {
//         vector<pair<int,int>> arr;

//         for(int i = lo; i <= hi; i++){
//             arr.push_back({power(i), i});
//         }

//         sort(arr.begin(), arr.end());

//         return arr[k-1].second;
//     }
// };



class Solution {
public:
    unordered_map<int, int> dp;

    int fun(int n) {
        if(n == 1) return 0;
        if(dp.count(n)) return dp[n];

        int even = 0;
        int odd = 0;
        if(n%2 == 0) even = 1 + fun(n/2);
        else odd = 1 + fun(3*n + 1);

        return dp[n] = even + odd;
    }

    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>> pq;

        while(lo <= hi) {
            int power = fun(lo);
            if(pq.size() < k) pq.push({power, lo});
            else if(pq.top().first > power) {
                pq.pop();
                pq.push({power, lo});
            }
            lo++;
        }

        return pq.top().second;
    }
};