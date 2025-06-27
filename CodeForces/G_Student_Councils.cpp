#include <bits/stdc++.h>
using namespace std;

bool good(long long mid, int k, vector<int>&arr){
    long long tot = 0;
    for(int i: arr){
        tot += min(mid, i*1ll);
    }

    return tot >= mid*k;
}

int main(){
    int k, n, sm=0;
    cin >> k >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sm += arr[i];
    }

    int left = 1;
    int right = sm;
    long long ans = 0;
    while(left <= right){
        int mid = (left+right)/2;
        if(good(mid, k, arr)){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    cout << ans;
}
