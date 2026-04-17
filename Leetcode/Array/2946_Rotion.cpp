#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int w = k % m;

        vector<vector<int>> arr(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i % 2 == 0) {
                    // right shift
                    arr[i][(j + w) % m] = mat[i][j];
                } 
                else {
                    // left shift
                    arr[i][(j - w + m) % m] = mat[i][j];
                }
            }
        }

        return arr == mat;
    }
};