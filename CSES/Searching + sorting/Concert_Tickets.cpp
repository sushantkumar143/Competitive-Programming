#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;

    multiset<int> mt;
    for(int x : a) mt.insert(x);

    int i=0;
    while(i<m) {
        auto it = mt.upper_bound(b[i]);
        if(it == mt.begin()) {
            cout << -1 << '\n';
            i++;
            continue;
        }
        else it--;
        cout << *it << '\n';
        mt.erase(it);   
        i++;
    }

    return 0;
}