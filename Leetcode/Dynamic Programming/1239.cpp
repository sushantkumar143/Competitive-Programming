#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(string& s) {
        int arr[26] = {0};
        for(char& ch : s) arr[ch-'a']++;
        for(int& i : arr) if(i>1) return true;
        return false;
    }

    int fun(int idx, string s, int n, vector<string>& arr) {
        if(idx == n) return s.length();

        int take = 0;
        int notTake = 0;
        string temp = s + arr[idx];

        if(hasDuplicate(temp)) {
            notTake = fun(idx+1, s, n, arr);
        }
        else {
            take = fun(idx+1, s+arr[idx], n, arr);
            notTake = fun(idx+1, s, n, arr);
        }

        return max(take, notTake);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string s = "";
        return fun(0, s, n, arr);
    }
};



// class Solution {
// public:
//     bool isValid(string &s) {
//         vector<int> freq(26, 0);
//         for(char c : s) {
//             freq[c - 'a']++;
//             if(freq[c - 'a'] > 1) return false;
//         }
//         return true;
//     }

//     void solve(int idx, string curr, vector<string>& arr, int &ans) {
//         if(!isValid(curr)) return;

//         ans = max(ans, (int)curr.length());

//         for(int i = idx; i < arr.size(); i++) {
//             solve(i + 1, curr + arr[i], arr, ans);
//         }
//     }

//     int maxLength(vector<string>& arr) {
//         int ans = 0;
//         solve(0, "", arr, ans);
//         return ans;
//     }
// };