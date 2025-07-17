#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        string a = "codeforces";
        int cnt = 0;
        for(int i=0; i<a.length(); i++){
            if(s[i] != a[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}
