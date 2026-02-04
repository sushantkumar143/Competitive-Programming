#include<bits/stdc++.h>
using namespace std;

// VERY GOOD INTUTIVE QUESTION   --- MUST TRY ---

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefix(n, 0), left(n), right(n);
        prefix[0] = (s[0] == '*');

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + (s[i]=='*');
        }

        int last = -1;
        for(int i=0; i<n; i++) {
            if(s[i] == '|') last = i;
            left[i] = last;
        }

        last = -1;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '|') last = i;
            right[i] = last;
        }

        vector<int> ans;
        for(auto q : queries) {
            int l = right[q[0]];
            int r = left[q[1]];

            if(l >= r || l == -1 || r == -1) ans.push_back(0);
            else {
                ans.push_back(prefix[r] - prefix[l]);
            }
        }

        return ans;
    }
};



// BRUTE FORCE

// class Solution {
// public:
//     int fun(string s, int left, int right) {
//         int cnt = 0;
//         while(left < right && s[left] != '|') left++;
//         while(left < right && s[right] != '|') right--;

//         for (int i = left + 1; i < right; i++) {
//             if (s[i] == '*') cnt++;
//         }
//         return cnt;
//     }

//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         int n = queries.size();
//         vector<int> ans;

//         for(int i=0; i<n; i++) {
//             int a = fun(s, queries[i][0], queries[i][1]);
//             ans.push_back(a);
//         }
//         return ans;
//     }
// };