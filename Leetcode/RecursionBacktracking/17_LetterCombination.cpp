#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int idx, string temp, string digits, unordered_map<int, string>& mp, vector<string>& ans) {
        if(idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string s = mp[digits[idx]-'0'];
        for(char ch : s) {
            fun(idx+1, temp+ch, digits, mp, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;

        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string> ans;
        fun(0, "", digits, mp, ans);

        return ans;
    }
};