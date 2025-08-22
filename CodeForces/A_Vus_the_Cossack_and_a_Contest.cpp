#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    if (m >= n && k >= n) 
        cout << "Yes\n";
    else 
        cout << "No\n";
    
    return 0;
}
