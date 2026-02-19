#include<bits/stdc++.h>
using namespace std;

// SIMILAR QUESTION IN LEETCODE
// 1839. Longest Substring Of All Vowels in Order 

// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.length();
        int i = 0;
        int maxi = 0;

        while(i < n) {
            int zero = 0;
            int one = 0;

            while(i < n && s[i] == '0') {
                zero++;
                i++;
            }

            while(i < n && s[i] == '1') {
                one++;
                i++;
            }

            maxi = max(maxi, 2 * min(zero, one));
        }

        return maxi;
    }
};
