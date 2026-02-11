#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string findOrder(vector<string> &words) {

        vector<vector<int>> adj(26);
        vector<int> present(26,0);
        int total = 0;

        for(auto &w: words){
            for(char c: w){
                if(!present[c-'a']){
                    present[c-'a'] = 1;
                    total++;
                }
            }
        }

        int n = words.size();

        for(int i=1;i<n;i++){
            string a = words[i-1];
            string b = words[i];

            int j=0;
            while(j<a.size() && j<b.size() && a[j]==b[j]) j++;

            if(j==b.size() && a.size()>b.size())
                return "";

            if(j<a.size() && j<b.size()){
                adj[a[j]-'a'].push_back(b[j]-'a');
            }
        }

        vector<int> indeg(26,0);

        for(int i=0;i<26;i++)
            for(int v: adj[i])
                indeg[v]++;

        queue<int> q;
        for(int i=0;i<26;i++)
            if(present[i] && indeg[i]==0)
                q.push(i);

        string ans="";

        while(!q.empty()){
            int u=q.front(); q.pop();
            ans.push_back(u+'a');

            for(int v: adj[u]){
                indeg[v]--;
                if(indeg[v]==0)
                    q.push(v);
            }
        }

        if(ans.size()!=total) return "";

        return ans;
    }
};
