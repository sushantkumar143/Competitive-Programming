#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        unordered_map<int, int> freq;
        int val;
        int ans = -1;

        for(int i = 0; i < n; i++){
            cin >> val;
            freq[val]++;
            if(freq[val] == 3) ans = val; 
        }

        cout << ans << '\n';
    }

    return 0;
}
