#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;

        sort(a.begin(), a.end());        
        sort(b.rbegin(), b.rend());    

        for(int i = 0; i < k && i < n; ++i){
            if(b[i] > a[i]) {
                swap(a[i], b[i]);
            } else break;
        }

        int sum = accumulate(a.begin(), a.end(), 0);
        cout << sum << '\n';
    }
}
