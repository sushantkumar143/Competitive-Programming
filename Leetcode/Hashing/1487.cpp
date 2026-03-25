#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> res;
        
        for(string& name : names) {
            if(mp.find(name) == mp.end()) {
                res.push_back(name);
                mp[name] = 1;
            }
            else {
                string newName;
                int k = mp[name];
                while(1) {
                    newName = name + '(' + to_string(k) + ')';
                    if(mp.find(newName) == mp.end()) {
                        break;
                    }
                    k++;
                }
                res.push_back(newName);
                mp[name] = k+1;
                mp[newName] = 1;
            }
        }

        return res;
    }
};