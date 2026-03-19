#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int cnt = t.length();
        int i=0;
        int j=0;
        int start = 0;
        int mini = 1e9;

        unordered_map<char, int> mp;
        for(char& ch : t) mp[ch]++;

        while(j < n) {
            if(mp[s[j]] > 0) cnt--;
            mp[s[j]]--;

            while(!cnt) {
                if(j-i+1 < mini) {
                    start = i;
                    mini = j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) cnt++;
                i++;
            }
            j++;
        }

        return mini == 1e9 ? "" : s.substr(start, mini);
    }
};


// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.length();
//         int k = t.length();
//         unordered_map<char, int> mp;
//         for(char& ch : t) {
//             mp[ch]++;
//         }
//         int i=0, j=0;
//         int cnt = 0;
//         int start = 0;
//         int mini = 1e9;

//         while(j < n) {
//             if (mp[s[j]] > 0) {
//                 cnt++;
//             }

//             mp[s[j]]--;

//             while(cnt == k) {
//                 if (j - i + 1 < mini) {
//                     mini = j - i + 1;
//                     start = i;
//                 }

//                 mp[s[i]]++;
//                 if(mp[s[i]] > 0) cnt--;
//                 i++;
//             }
//             j++;
//         }

//         return mini==1e9 ? "" : s.substr(start, mini);
//     }
// };