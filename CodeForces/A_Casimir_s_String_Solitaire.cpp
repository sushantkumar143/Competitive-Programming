#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int countA = 0, countB = 0, countC = 0;
        for(char c : s) {
            if(c == 'A') countA++;
            else if(c == 'B') countB++;
            else if(c == 'C') countC++;
        }

        if(countB == countA + countC) cout << "YES\n";
        else cout << "NO\n";
    }
}
