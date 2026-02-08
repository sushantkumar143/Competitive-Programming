#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        
        int x = 0, y = 0;
        visited.insert({0, 0});

        for (char ch : path) {
            if (ch == 'N') x--;
            else if (ch == 'S') x++;
            else if (ch == 'E') y++;
            else y--;

            if (visited.count({x, y}))
                return true;

            visited.insert({x, y});
        }
        return false;
    }
};