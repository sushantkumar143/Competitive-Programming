#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxi = 0;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxi = max(maxi, freq[s[right] - 'A']);

            int replacements = (right - left + 1) - maxi;

            while (replacements > k) {
                freq[s[left] - 'A']--;
                left++;
                replacements = (right - left + 1) - maxi;
            }

            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};