#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        if (a + (c + 1) / 2 > b + c / 2)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    
    return 0;
}
