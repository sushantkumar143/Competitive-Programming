#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;

        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for(int i=1; i<n; i++) {
            int a = ugly[i2]*2;
            int b = ugly[i3]*3;
            int c = ugly[i5]*5;

            int nextUgly = min({a, b, c});

            if(nextUgly == a) i2++;
            if(nextUgly == b) i3++;
            if(nextUgly == c) i5++;

            ugly[i] = nextUgly;
        }

        return ugly[n-1];
    }
};



// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         priority_queue<long, vector<long>, greater<long>> pq;
//         unordered_set<long> seen;

//         pq.push(1);
//         seen.insert(1);

//         long curr = 1;

//         while(n--) {
//             curr = pq.top();
//             pq.pop();

//             if(!seen.count(curr * 2)) {
//                 pq.push(curr * 2);
//                 seen.insert(curr * 2);
//             }

//             if(!seen.count(curr * 3)) {
//                 pq.push(curr * 3);
//                 seen.insert(curr * 3);
//             }

//             if(!seen.count(curr * 5)) {
//                 pq.push(curr * 5);
//                 seen.insert(curr * 5);
//             }
//         }

//         return curr;
//     }
// };