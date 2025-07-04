#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans = "";

    for(char ch : s){
        if(ans == "" && ch == 'h') ans += ch;
        else if(ans == "h" && ch == 'e') ans += ch;
        else if(ans == "he" && ch == 'l') ans += ch;
        else if(ans == "hel" && ch == 'l') ans += ch;
        else if(ans == "hell" && ch == 'o') ans += ch;
        
        if(ans == "hello"){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}