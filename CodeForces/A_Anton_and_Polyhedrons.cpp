#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long ans = 0;

    while(t--){
        string s;
        cin >> s;
        if(s == "Icosahedron") ans += 20;
        else if(s == "Cube") ans += 6;
        else if(s == "Tetrahedron") ans += 4;
        else if(s == "Dodecahedron") ans += 12;
        else ans += 8;
    }

    cout << ans;
}