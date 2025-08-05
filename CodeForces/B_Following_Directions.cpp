#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int x = 0;
        int y = 0;
        bool flag = false;

        while(n--){
            char ch;
            cin >> ch;
            
            if(ch == 'U') y++;
            else if(ch == 'R') x++;
            else if(ch == 'D') y--;
            else if(ch == 'L') x--;

            if(x==1 && y==1) flag = true;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}