#include <iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        bool ans = true;

        for(int i=0; i<n; i++){
            if((s1[i] == 'R' && s2[i] != 'R') || (s2[i]=='R' && s1[i] != 'R')) ans = false;
        }
        
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
