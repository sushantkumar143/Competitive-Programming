#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(string &pat, string &s) {
        int n = s.length();
        int m = pat.length();

        unordered_map<char, int> mp;
        for (char ch : pat) mp[ch]++;

        int count = mp.size();  // unique chars
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            // if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            // }

            if (j - i + 1 < m) {
                j++;
            }
            else if (j - i + 1 == m) {

                if (count == 0)
                    ans++;

                // if (mp.find(s[i]) != mp.end()) {
                    if (mp[s[i]] == 0)
                        count++;
                    mp[s[i]]++;
                // }

                i++;
                j++;
            }
        }

        return ans;
    }
};