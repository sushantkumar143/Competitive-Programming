#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = s.length();
    int cnt = 0;
    for(int i=1; i<k; i++){
        if(s[i]==s[i-1]) cnt++;
    }
    cout << cnt;
}