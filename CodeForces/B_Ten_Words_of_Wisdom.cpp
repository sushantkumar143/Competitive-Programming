#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int ans = -1;
        int maxi = -1;
        int cnt = 0;

        while(n--){
            cnt++;
            int num, quality;
            cin >> num >> quality;

            if(num <= 10 && quality > maxi){
                maxi = quality;
                ans = cnt;
            }
        }

        cout << ans << '\n';
    }
}