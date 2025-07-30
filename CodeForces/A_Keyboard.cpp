#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch;
    cin >> ch;

    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";

    string q;
    cin >> q;
    string ans = "";

    if(ch == 'R'){
        for(int i=0; i<q.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(q[i] == s[j])  ans += s[j-1];
            }
        }
    }
    if(ch == 'L'){
        for(int i=0; i<q.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(q[i] == s[j])  ans += s[j+1];
            }
        }
    }
    cout << ans;
}