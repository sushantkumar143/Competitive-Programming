#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch;
            cin >> ch;
            if(ch != 'W' && ch != 'B' && ch!='G') flag = true;
        }
    }

    if(flag) cout << "#Color\n";
    else cout << "#Black&White\n";
}