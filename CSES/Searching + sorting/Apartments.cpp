#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    int i=0;
    int j=0;

    while(i<n && j<m) {
        if(a[i]+k >= b[j] && a[i]-k <= b[j]) {
            cnt++;
            i++;
            j++;
        }
        else if(a[i] <= b[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << cnt;

    return 0;
}