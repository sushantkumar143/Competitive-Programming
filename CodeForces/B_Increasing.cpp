#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto& x : arr) cin >> x;

        unordered_map<int, int> map;
        for(int i : arr){
            map[i]++;
        }
        bool flag = false;
        for(auto i : map){
            if(i.second > 1){
                cout << "NO\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "YES\n";
    }
}
