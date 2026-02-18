#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int conv(string s) {
        return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
    }

    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        int s1 = conv(e1[0]);
        int t1 = conv(e1[1]);
        int s2 = conv(e2[0]);
        int t2 = conv(e2[1]);

        return max(s1, s2) <= min(t1, t2);
    }
};
