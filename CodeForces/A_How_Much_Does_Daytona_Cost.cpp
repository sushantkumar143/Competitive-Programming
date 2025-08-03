#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for(int &x : arr) cin >> x;
        bool flag = false;

        for(int i : arr){
            if(k == i){
                flag = true;
                break;
            }
        }

        if(!flag) cout << "NO\n";
        else cout << "YES\n";
    }
}