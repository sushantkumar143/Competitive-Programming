#include<bits/stdc++.h>
using namespace std;

int fun(int n, string& s) {
    int bal = 0;
    int moves = 0;

    for(int i=0; i<n; i++) {
        if(s[i] == '(') {
            bal++;
        }
        else {
            if(bal > 0) bal--;
            else moves++;
        }
    }

    return moves;
}

int main() {
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << fun(n, s) << '\n';
    }
}