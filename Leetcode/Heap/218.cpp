#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>> events;
        
        for(auto &b : buildings) {
            events.push_back({b[0], -b[2]}); // start
            events.push_back({b[1], b[2]});  // end
        }
        
        sort(events.begin(), events.end());
        
        multiset<int> heights;
        heights.insert(0);
        
        int prevMax = 0;
        vector<vector<int>> result;
        
        for(auto &e : events) {
            
            int x = e.first;
            int h = e.second;
            
            if(h < 0) {
                heights.insert(-h);
            }
            else {
                heights.erase(heights.find(h));
            }
            
            int currMax = *heights.rbegin();
            
            if(currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }
        
        return result;
    }
};