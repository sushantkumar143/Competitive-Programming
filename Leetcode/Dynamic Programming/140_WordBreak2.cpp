#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int idx, string temp, string& s, vector<string>& res, unordered_set<string>& st) {
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }

        for(int i=idx+1; i<=s.length(); i++) {
            string t = s.substr(idx, i-idx);
            if(st.count(t)) {
                if(temp.empty())
                    fun(i, t, s, res, st);
                else
                    fun(i, temp + " " + t, s, res, st);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> res;

        fun(0, "", s, res, st);
        return res;
    }
};