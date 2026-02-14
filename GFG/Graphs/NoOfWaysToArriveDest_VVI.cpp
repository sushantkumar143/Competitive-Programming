#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?page=2&category=Graph&sortBy=submissions

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        const int MOD = 1e9+7;

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){

            auto [d,node]=pq.top();
            pq.pop();

            if(d>dist[node]) continue;

            for(auto &it:adj[node]){
                int neigh=it.first;
                int w=it.second;

                long long nd=d+w;

                if(nd < dist[neigh]){
                    dist[neigh]=nd;
                    ways[neigh]=ways[node];
                    pq.push({nd,neigh});
                }
                else if(nd == dist[neigh]){
                    ways[neigh]=(ways[neigh]+ways[node])%MOD;
                }
            }
        }

        return ways[V-1];
    }
};
