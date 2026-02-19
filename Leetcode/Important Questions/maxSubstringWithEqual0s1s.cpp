// Length of the longest substring with equal 1s and 0s

#include<bits/stdc++.h>
using namespace std;

int isValid(string s) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sm = 0;
    int ans = 0;
    int n = s.length();

    for(int i=0; i<n; i++) {
        sm += (s[i] == '0') ? -1 : 1;

        if(mp.count(sm)) {
            ans = max(ans, i - mp[sm]);
        }        
        else mp[sm] = i;
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << isValid(s) << endl;
}