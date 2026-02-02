//  FLOYD WARSHAL ALGO APPLIED

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = cost.size();
        long long INF = 1e18;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for(int i=0; i<26; i++) {
            dist[i][i] = 0;
        }
        for(int i=0; i<m; i++) {
            long long src = original[i] - 'a';
            long long dest = changed[i] - 'a';
            dist[src][dest] = min(dist[src][dest], (long long)cost[i]);
        }

        for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    if(dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<n; i++) {
            long long d = dist[source[i]-'a'][target[i]-'a'];
            if (d == INF) return -1;
            ans += d;
        }

        return ans;
    }
};