#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if(s.length() < 7){
        cout << "NO";
        return 0;
    }

    int cnt = 1;
    char last = s[0];

    for(int i=1; i<s.length(); i++){
        if(cnt == 7){
            cout << "YES";
            return 0;
        }
        if(s[i] == last){
            cnt++;
        }
        else{
            cnt = 1;
            last = s[i];
        }
    }

    cout << "NO";
}
