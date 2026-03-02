#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int binaryGap(int n) {
//         string s = "";
//         while(n) {
//             char digit = (n%2) + '0';
//             s += digit;
//             n /= 2;
//         }
//         reverse(s.begin(), s.end());

//         int left = 0;
//         char last = '9';
//         int ans = 0;
//         n = s.length();

//         for(int i=0; i<n; i++) {
//             if(s[i] == '1') {
//                 if(last == '1') {
//                     ans = max(ans, i-left);
//                 }
//                 last = '1';
//                 left = i;
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int ans = 0;
        int index = 0;

        while(n > 0) {
            if(n & 1) {
                if(last != -1) {
                    ans = max(ans, index - last);
                }
                last = index;
            }
            index++;
            n >>= 1;
        }

        return ans;
    }
};