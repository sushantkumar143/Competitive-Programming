#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int a = -1;
        int b = -1;
        for(int i=1; i<s.size(); i++) {
            if(s[i] != s[i-1]){
                a = i;
                b = i-1;
                break;
            }
        }
        
        if(a != b){ 
            cout << "YES\n";
            swap(s[a], s[b]);
            cout << s << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
}