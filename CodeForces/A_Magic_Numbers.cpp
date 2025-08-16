#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    bool flag = true;
    for (int i = 0; i < n.size();) {
        if (n.substr(i, 3) == "144") {
            i += 3;
        } 
        else if (n.substr(i, 2) == "14") {
            i += 2;
        } 
        else if (n.substr(i, 1) == "1") {
            i += 1;
        } 
        else {
            flag = false;
            break;
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";

}
