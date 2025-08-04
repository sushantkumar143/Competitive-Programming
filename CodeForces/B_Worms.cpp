#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> prefix(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0)
            prefix[i] = a[i];
        else
            prefix[i] = prefix[i - 1] + a[i];
    }

    int m;
    cin >> m;
    
    while (m--) {
        int q;
        cin >> q;

        int pile = lower_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
        
        cout << (pile + 1) << endl;
    }

    return 0;
}
