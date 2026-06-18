#include<bits/stdc++.h>
using namespace std;

// NOTE: WHENEVER WE NEED TO HASH ANY VECTOR THEN SIMPLY WE CAN ENCODE THAT VECTOR INTO STRING AND CAN EMBED INTO THE MAP

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> mp;

        // store rows
        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                s += to_string(grid[i][j]) + "#";
            }
            mp[s]++;
        }

        int cnt = 0;

        // match columns
        for(int j = 0; j < n; j++) {
            string s = "";
            for(int i = 0; i < n; i++) {
                s += to_string(grid[i][j]) + "#";
            }
            cnt += mp[s];
        }

        return cnt;
    }
};