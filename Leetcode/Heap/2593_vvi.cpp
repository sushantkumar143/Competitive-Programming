#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>> pq;
        
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        vector<bool> visited(n, false);
        long long score = 0;
        
        while(!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            
            if(visited[idx]) continue;
            
            score += val;
            
            visited[idx] = true;
            if(idx-1 >= 0) visited[idx-1] = true;
            if(idx+1 < n) visited[idx+1] = true;
        }
        
        return score;
    }
};