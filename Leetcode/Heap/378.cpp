#include<bits/stdc++.h>
using namespace std;

// VERY GOOD INTUTIVE QUESTION   --- MUST TRY ---

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        // push first element of each row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        while (--k) {
            auto [val, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if (c + 1 < n) {
                pq.push({matrix[r][c + 1], {r, c + 1}});
            }
        }

        return pq.top().first;
    }
};
