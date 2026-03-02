#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(k == 0) return 0;

    unordered_map<char,int> mp;
    int left = 0;
    int maxLen = 0;

    for(int right = 0; right < s.length(); right++) {
        mp[s[right]]++;

        while(mp.size() > k) {
            mp[s[left]]--;
            if(mp[s[left]] == 0) {
                mp.erase(s[left]);
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}