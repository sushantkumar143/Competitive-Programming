#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0) {
                len = lps[len - 1];
            } 
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool checkString(const string &s1, const string &s2) {
    vector<int> lps = buildLPS(s1);
    int i = 0, j = 0;
    int n = s2.size(), m = s1.size();

    while (i < n) {
        if (s1[j] == s2[i]) {
            i++;
            j++;
        }
        if (j == m) {
            return true;
        } 
        else if (i < n && s1[j] != s2[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        string temp = a;
        int cnt = 0;
        bool found = false;

        while ((int)temp.size() < m) {
            temp += temp;
            cnt++;
        }

        if (checkString(b, temp)) {
            cout << cnt << "\n";
            found = true;
        } 
        else {
            temp += a;
            cnt++;
            if (checkString(b, temp)) {
                cout << cnt << "\n";
                found = true;
            }
        }

        if (!found) cout << -1 << "\n";
    }
}
