#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        
        int total = 0;
        for(int x : possible)
            total += (x == 1 ? 1 : -1);
        
        int prefix = 0;
        
        for(int i = 0; i < n-1; i++) {
            prefix += (possible[i] == 1 ? 1 : -1);
            
            int bob = total - prefix;
            
            if(prefix > bob)
                return i + 1;
        }
        
        return -1;
    }
};