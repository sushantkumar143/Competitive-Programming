#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        char ch;
        string ans = "";
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cin >> ch;
                if(ch != '.') ans += ch;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
