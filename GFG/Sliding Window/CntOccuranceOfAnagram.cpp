#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        unordered_map<char, int> mp;
        for(char& ch : pat) {
            mp[ch]++;
        }
        int req = pat.size();
        int n = txt.size();
        int k = pat.length();
        int left = 0;
        int res = 0;
        
        for(int right=0; right<n; right++) {
            if(mp[txt[right]] > 0) req--;
            mp[txt[right]]--;
            
            if(right-left+1 == k) {
                if(req == 0) res++;
                
                mp[txt[left]]++;
                if(mp[txt[left]] > 0) req++;
                left++;
            }
        }
        
        return res;
    }
};