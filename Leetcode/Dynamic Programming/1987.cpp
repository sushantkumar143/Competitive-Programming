#include<bits/stdc++.h>
using namespace std;

// LEETCODE HARD TAG
// 1987. Number of Unique Good Subsequences

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfUniqueGoodSubsequences(string binary) {
        int end0 = 0;
        int end1 = 0;
        int has0 = 0;

        for(char& ch : binary) {
            if(ch == '1') {
                end1 = (end1 + end0 + 1) % MOD;
            }
            else {
                end0 = (end1 + end0) % MOD;
                has0 = 1;
            }
        }

        return (end0 + end1 + has0) % MOD;
    }
};