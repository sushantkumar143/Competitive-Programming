#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int a = 0;
        int b = 0;
        for(char ch : s){
            if(ch == 'A') a++;
            else b++;
        }
        if(a>=b) cout << "A\n";
        else cout << "B\n";
    }

    return 0;
}
