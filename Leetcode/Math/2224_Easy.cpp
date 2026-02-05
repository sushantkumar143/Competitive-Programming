#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int ch = (current[0]-'0')*10 + (current[1]-'0');
        int cm = (current[3]-'0')*10 + (current[4]-'0');
        int rh = (correct[0]-'0')*10 + (correct[1]-'0');
        int rm = (correct[3]-'0')*10 + (correct[4]-'0');

        int cur = ch * 60 + cm;
        int cor = rh * 60 + rm;
        int total = cor - cur;

        int steps[] = {60, 15, 5, 1};
        int cnt = 0;

        for(int s : steps) {
            cnt += total / s;
            total %= s;
        }

        return cnt;
    }
};