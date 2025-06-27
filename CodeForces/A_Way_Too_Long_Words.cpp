#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        
        if(n<=10){
            cout << s << "\n";
        }
        else{
            string ans = "";
            ans += s[0];
            ans += to_string(n-2);
            ans += s[n-1];
            cout << ans << "\n";
        }
    }
}