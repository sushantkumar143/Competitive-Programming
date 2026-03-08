#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {

        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(maxTime+1, INT_MAX));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>
        > pq;

        pq.push({passingFees[0],0,0});
        dist[0][0] = passingFees[0];

        while(!pq.empty()){

            auto [cost,node,time] = pq.top();
            pq.pop();

            if(node == n-1) return cost;

            for(auto &neigh : adj[node]){
                int next = neigh.first;
                int t = neigh.second;
                int newTime = time + t;

                if(newTime > maxTime) continue;

                int newCost = cost + passingFees[next];
                if(newCost < dist[next][newTime]){
                    dist[next][newTime] = newCost;
                    pq.push({newCost,next,newTime});
                }
            }
        }

        return -1;
    }
};