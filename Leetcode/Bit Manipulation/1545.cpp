#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        long long length = (1 << n) - 1;
        int mid = (length/2) +1;

        if(mid == k) return '1';
        else if(mid > k) return findKthBit(n-1, k);
        else {
            char temp = findKthBit(n-1, length-k+1);
            return temp == '0' ? '1' : '0';
        }
    }
};



// class Solution {
// public:
//     string fun(string& s) {
//         string res = "";
//         for(char& ch : s) {
//             res += (ch == '0' ? '1' : '0');
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     } 

//     char findKthBit(int n, int k) {
//         string s = "0";
//         string temp = s;

//         while(s.length() <= k) {
//             s += '1';
//             s += fun(temp);
//             temp = s;
//         }

//         cout << s << '\n';

//         return s[k-1];
//     }
// };