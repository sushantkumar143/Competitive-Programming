#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> res;

        for(int i = 0; i < arr.size(); i++) {
            
            if(arr[i] < 0) {
                q.push(arr[i]);
            }

            if(i >= k - 1) {
                
                res.push_back(q.empty() ? 0 : q.front());

                if(!q.empty() && arr[i - k + 1] == q.front()) {
                    q.pop();
                }
            }
        }

        return res;
    }
};