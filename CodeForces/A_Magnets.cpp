#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string check = "oo";
    int cnt = 0;

    while(n--){
        string s;
        cin >> s;
        if(check != s){
            cnt++;
            check = s;
        }
    }
    cout << cnt;
}