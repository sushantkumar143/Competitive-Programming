#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        int freq[10] = {0};
        for(char c : num) freq[c - '0']++;

        string left = "";

        for(int d = 9; d >= 0; d--) {
            int k = freq[d] / 2;

            if(d == 0 && left.empty()) continue;

            left.append(k, char(d + '0'));
            freq[d] -= 2 * k;
        }

        char mid = 0;
        for(int d = 9; d >= 0; d--) {
            if(freq[d] > 0) {
                mid = char(d + '0');
                break;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;
        if(mid) ans.push_back(mid);
        ans += right;

        if(ans.empty()) return "0";

        return ans;
    }
};
