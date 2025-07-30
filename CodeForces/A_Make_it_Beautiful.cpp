#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        bool allEqual = true;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[0]) {
                allEqual = false;
                break;
            }
        }

        if(allEqual) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            sort(a.rbegin(), a.rend());
            for(int x : a) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
