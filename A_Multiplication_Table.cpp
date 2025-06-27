#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    for(int i=1; i*i<=k; i++){
        if(k%i == 0){
            int factor1 = i;
            int factor2 = k/i;
            // cout << factor1 << " " << factor2 << endl;
            if(factor1<=n && factor2<=n) {
                cnt++;
                if( factor1 != factor2){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}