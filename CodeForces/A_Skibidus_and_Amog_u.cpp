#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        s.replace(s.length()-2, 2, "i");
        cout << s<<'\n';
    }
}