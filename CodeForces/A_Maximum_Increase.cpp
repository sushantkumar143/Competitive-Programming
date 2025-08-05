#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &x : arr) cin >> x;
    if(n == 1){
        cout << 1;
        return 0;
    }

    int ans = 0;
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]) cnt++;
        else{
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}