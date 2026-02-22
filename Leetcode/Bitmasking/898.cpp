#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> prev, curr;
        set<int> res;

        for(int x : arr) {
            curr.clear();
            curr.insert(x);
            
            for(int p : prev) {
                curr.insert(p | x);
            }

            prev = curr;

            for(int c : curr) {
                res.insert(c);
            }
        }

        return res.size();
    }
};