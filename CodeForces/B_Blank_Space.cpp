#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int sm = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                sm++;
            } else {
                maxi = max(sm, maxi);
                sm = 0;
            }
        }
        maxi = max(sm, maxi);
        cout << maxi << '\n';
    }
}
